#include<iostream>
#include<cstring>
#include<cmath>
#define inf 1e6
using namespace std;
int graph[1005][1005];
int dist[1005];
int visited[1005];

int Prim(int n)
{
    memset(visited,0,sizeof(visited));
    memset(dist,inf,sizeof(dist));
    int ans=0;
    visited[1]=1;
    for(int j = 2;j<=n;j++) dist[j]=min(dist[j],graph[1][j]);
    for(int i=2;i<=n;i++)
    {
        int min=inf;
        int min_point=-1;
        for(int j=1;j<=n;j++)
        {
            if(visited[j]==0 && min>dist[j])
            {
                min=dist[j];
                min_point = j;
            }
        }
        if(min_point==-1) 
        {
            return inf;
        }
        else
        {
            visited[min_point]=1;
            ans+=min;
            for(int j= 1;j<=n;j++) 
            {
                dist[j] = (dist[j]>graph[min_point][j]) ? graph[min_point][j]:dist[j] ;
            }
        }
    }
    return ans;
}

int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++) memset(graph[i],inf,sizeof(graph[i]));
    for(int i=0;i<m;i++)
    {
        int a,b,dis;
        cin>>a>>b>>dis;
        graph[a][b]=dis;
        graph[b][a]=dis;
    }
    int ans= Prim(n);
    if(ans!=inf) cout<<ans;
    else cout<<-1;
    return 0;
}