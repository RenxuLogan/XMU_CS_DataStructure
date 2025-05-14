#include<iostream>
#include<cstring>
#define inf 1000*1000
using  namespace std;


int visited[105];
int dist[105];
int g[105][105];


int dijkstra(int start,int n)
{
    memset(visited,0,sizeof(visited));
    memset(dist,inf,sizeof(dist));
    visited[start]=1;
    dist[start]=0;
    for(int i=1;i<=n;i++) dist[i]=min(dist[i],g[start][i]);
    for(int i=2;i<=n;i++)
    {
        int min=inf;
        int min_point=-1;
        for(int j=1;j<=n;j++)
        {
            if(visited[j]==0 && dist[j]<min)
            {
                min_point=j;
                min=dist[j];
            }
        }
        if(min_point==-1) return -1;
        visited[min_point]=1;
        for(int j=1;j<=n;j++) 
        {
            dist[j]=dist[j]>dist[min_point]+g[min_point][j]?dist[min_point]+g[min_point][j]:dist[j];
        }
    }
    int min_point=0;
    int min=inf;
    for(int i=1;i<=n;i++)
    {
        if(i!=start && dist[i]>min)
        {
            min=dist[i];
            min_point=i;
        }
    }
    return min_point;
}



int main()
{
    int n , m;
    cin>>n>>m;
    for(int i=0;i<=n;i++) memset(g[i],inf,sizeof(g[i]));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=c;
        g[b][a]=c;
    }
    int ans=inf;
    int min_point=-1;
    for(int i=1;i<=n;i++)
    {
        int min = dijkstra(i,n);
        if(min!= -1 && dist[min]<ans)
        {
            ans=dist[min];
            min_point = i;
        }

    }
    if(min_point == -1)cout<<0;
    else cout<<min_point<<" "<<ans;
    return 0;
}