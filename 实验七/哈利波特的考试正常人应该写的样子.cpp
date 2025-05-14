#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define MAX_SIZE 101
#define INF 1e6

int n, m;
int graph[MAX_SIZE][MAX_SIZE];

int dijkstra(int start) {
    int dis[MAX_SIZE];
    int vis[MAX_SIZE] = {0};
    fill(dis, dis + MAX_SIZE, INF);//初始化
    dis[start] = 0;

    for (int i = 1; i <= n; i++) {
        int min_dist = INF, pos = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] < min_dist) {
                min_dist = dis[j];
                pos = j;
            }
        }

        if (pos == -1) return -1; // 有节点无法到达
        vis[pos] = 1;

        for (int j = 1; j <= n; j++) {//更新dis->可以看出dis表示从start到j的最短路径，如果有path数组那么还可以记录路径
            if (!vis[j] && graph[pos][j] < INF) {
                dis[j] = min(dis[j], dis[pos] + graph[pos][j]);
            }
        }
    }

    int max_dist = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) return -1; // 存在无法到达的节点
        max_dist = max(max_dist, dis[i]);
    }
    return max_dist;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, len;
        cin >> a >> b >> len;
        graph[a][b] = len;
        graph[b][a] = len; // 无向图
    }

    int ans = INF, min_start = -1;
    for (int i = 1; i <= n; i++) {
        int tmp = dijkstra(i);
        if (tmp != -1 && tmp < ans) {
            ans = tmp;
            min_start = i;
        }
    }

    if (min_start == -1) {
        cout << 0 << endl;
    } else {
        cout << min_start << " " << ans << endl;
    }

    return 0;
}
