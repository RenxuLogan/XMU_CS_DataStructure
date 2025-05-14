#include<iostream>
#include<cstring>
#define inf 1e8

using namespace std;
typedef struct node
{
    int price;
    int dist;
}node;
node g[505][505];

int dist[505];
int price[505];
int visited[505];

void dijkstra (int start,int target,int n)
{
    memset(dist,inf,sizeof(dist));
    memset(visited,0,sizeof(visited));
    memset(price,0,sizeof(price));
    visited[start]=1;
    dist[start]=0;
    for(int i = 0 ; i < n ; i++)
    {
        if(g[start][i].dist!=inf)
        {
            dist[i]=g[start][i].dist;
            price[i]=g[start][i].price;
        }
    }
    for(int i=0;i<n;i++)
    {
        int min_point =-1;
        int min=inf;
        for(int j=0;j<n;j++)
        {
            if(visited[j] == 0 && dist[j]<min)
            {//肯定要选择当前最小的往前走
                min_point = j;
                min=dist[j];
            }
        }
        if(min_point==-1)return ;
        visited[min_point]=1;
        for(int j=0;j<n;j++)
        {
            if(dist[j]>dist[min_point]+g[min_point][j].dist)
            {
                dist[j]=dist[min_point]+g[min_point][j].dist;
                price[j]=price[min_point]+g[min_point][j].price;
            }else if(dist[j]==dist[min_point]+g[min_point][j].dist && price[j]>price[min_point]+g[min_point][j].price)
            {
                price[j]=price[min_point]+g[min_point][j].price;
            }
        }
    }

}
int main()
{
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    for (int i = 0; i < 505; ++i)
    {
        for (int j = 0; j < 505; ++j)
        {
            if(i!=j) g[i][j].dist = inf;
            else g[i][j].dist = 0;
            g[i][j].price = 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,dis,p;
        cin>>a>>b>>dis>>p;
        g[a][b].dist=dis;
        g[a][b].price=p;
        g[b][a].dist=dis;
        g[b][a].price=p;        
    }
    dijkstra(s,d,n);
    cout<<dist[d]<<" "<<price[d];
    return 0;
}