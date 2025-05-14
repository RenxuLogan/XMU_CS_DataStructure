#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int graph [1005][1005];
int visited [1005];
int dis [1005];
int bfs(int node,int n)
{
    queue<int> q;
    q.push(node);
    int count = 0;
    while(q.size()!=0 && dis[node]!=6)
    {
        node = q.front();
        q.pop();
        for(int i = 1;i<=n;i++)
        {
            if(visited[i]== 0 && graph[node][i] == 1)
            {
                q.push(i);
                visited[i]=1;
                dis[i]=dis[node]+1;
                if(dis[i]<=6)count++;
            }
        }
    }
    return count;
}



int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++) memset(graph[i],0,sizeof(graph[i]));
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    for(int i=1;i<=n;i++)
    {
        memset(visited,0,sizeof(visited));
        memset(dis,0,sizeof(dis));
        int ans=bfs(i,n);
        printf("%d: %.2f%%\n",i,((float)ans/n)*100);
    }
    return 0;

}