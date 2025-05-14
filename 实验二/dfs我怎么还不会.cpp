#include<iostream>
#include<vector>
using namespace std;

int maze[10][10];   // 迷宫
bool visited[10][10]; // 访问标记
int n;

vector<int> result_x;  // 存储路径的x坐标
vector<int> result_y;  // 存储路径的y坐标

// 深度优先搜索
bool dfs(int start_x, int start_y) {
    int dx[4] = {0, 1, 0, -1}; // x变化
    int dy[4] = {1, 0, -1, 0}; // y变化
    //x是竖着的轴，y是横着的轴
    // 如果到达目标位置，返回true
    if (start_x == n - 2 && start_y == n - 2) {
        result_x.push_back(start_x);
        result_y.push_back(start_y);
        return true;
    }

    // 如果当前点不可走或者已经访问过，返回false
    if (maze[start_x][start_y] == 1 || visited[start_x][start_y]) {
        return false;
    }

    // 标记为已访问
    visited[start_x][start_y] = true;

    // 记录当前点
    result_x.push_back(start_x);
    result_y.push_back(start_y);

    // 尝试四个方向
    for (int i = 0; i < 4; i++) {
        int new_x = start_x + dx[i];
        int new_y = start_y + dy[i];

        // 检查新坐标是否越界
        if (new_x >= 1 && new_x < n-1 && new_y >= 1 && new_y < n-1) {
            if (dfs(new_x, new_y)) {
                return true;  // 如果找到正确的路径，则返回true
            }
        }
    }

    // 如果没有找到路径，回溯，撤销当前点
    result_x.pop_back();
    result_y.pop_back();
    return false;
}

int main() {
    cin >> n;

    // 输入迷宫
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            visited[i][j] = false; // 初始化所有点为未访问
        }
    }

    int start_x = 1, start_y = 1;
    if (dfs(start_x, start_y)) {
        // 打印路径
        for (int i = 0; i < result_x.size(); i++) {
            cout << "(" << result_x[i] << "," << result_y[i] << ")";
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
