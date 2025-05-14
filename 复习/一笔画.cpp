#include<iostream>
#include<cstring>
using namespace std;
int graph[1005][1005];
int Degree[1005];
int visited[1005];

void dfs(int node,int n)
{
    visited[node]=1;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 && graph[node][i]==1) dfs(i,n);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++) memset(graph[i],0,sizeof(graph[i]));
    memset(Degree,0,sizeof(Degree));
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        Degree[a]++;
        Degree[b]++;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    dfs(1,n);
    int odd_count = 0;
    int count = 0;
    for(int i=1;i<=n;i++)    
    {
        if(visited[i]) count ++;
        if(Degree[i]% 2 ==1) odd_count++;
    }
    if(odd_count > 2 || count != n) cout<< "N";
    else cout << "Y";
    return 0;
}