#include<iostream>
using namespace std;
#define MAX_DISTANCE 5000*5000
#define MAX_SIZE 505
typedef struct node
{
    int price;
    int distance;
} graph[505][505];
graph G;
int n,m,s,d;
int dis[MAX_SIZE];
int vis[MAX_SIZE];
int cost[MAX_SIZE];

void dijkstra(int start)
{
    fill(dis,dis+MAX_SIZE,MAX_DISTANCE);
    dis[start]=0;
    vis[start]=1;
    for(int i=0;i<n;i++)
    {
        dis[i]=min(dis[i],dis[start]+G[i][start].distance);
        cost[i]=G[i][start].price;
    }

    for(int i=0;i<n;i++)
    {
        int min=MAX_DISTANCE;int pos=-1;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==0 && dis[j]<min)
            {
                min=dis[j];
                pos=j;
            }
        }
        if(pos==-1)
        {
            return ;
        }
        vis[pos]=1;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==0 && G[pos][j].distance!=MAX_DISTANCE)
            {
                if(dis[j]>dis[pos]+G[pos][j].distance)
                {
                    dis[j]=dis[pos]+G[pos][j].distance;
                    cost[j]=cost[pos]+G[pos][j].price;
                }else if(dis[j]==dis[pos]+G[pos][j].distance && cost[j]>cost[pos]+G[pos][j].price)
                {
                    cost[j]=cost[pos]+G[pos][j].price;
                }
            }
        }
    }
}


int main()
{
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j].distance = i==j?0:MAX_DISTANCE;
        }
    }

    for(int i=0;i<m;i++)
    {
        int a,b,len,price;
        cin>>a>>b>>len>>price;
        G[a][b].price=price;
        G[a][b].distance=len;
        G[b][a].price=price;
        G[b][a].distance=len;
    }
    dijkstra(s);
    cout<<dis[d]<<" "<<cost[d];
    return 0;

}