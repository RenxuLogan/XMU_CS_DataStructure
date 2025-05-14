#include<iostream>
using namespace std;
#define MAX_DISTANCE 5000*5000
int n,m,s,d;
typedef struct node
{
    int price;
    int distance;
}node_list[500][500];

node_list list;

int vis[500]; //vis[j]=1表示该顶点已进入集合S，vis[j]=0表示未进入集合S
int dis[500]; //用来存储源点到各顶点的最短路径值
int path[500];  //用来存储当前节点的前驱，通过回溯课获得完整最短路径
int cost[500];




void dijkstra(int start)
{
    for(int i=0;i<n;i++)
    {
        dis[i]=list[start][i].distance;
        cost[i]=list[start][i].price;
        path[i]=start; // 记录前驱节点，既然是初始化那么就是start
    }
    vis[start]=1;
    path[start]=-1; // 初始化前驱节点为-1

    int pos;
    for(int i=0;i<n;i++)
    {
        int min=MAX_DISTANCE + 1 ;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==0 && dis[j] <min )
            {
                pos=j;
                min= dis[j];
            }
        }
        vis[pos]=1;
        // 更新dis
        for(int j=0;j<n;j++)
        {
            if( vis[j]==0 && (list[pos][j].distance<MAX_DISTANCE && (dis[pos]+list[pos][j].distance)<dis[j]  )  )
            {
                dis[j]=dis[pos]+list[pos][j].distance;
                path[j]=pos; // 更新前驱节点
                cost[j]=cost[pos]+list[pos][j].price; // 更新cost[j]
            }
            else if( vis[j]==0 && (list[pos][j].distance<MAX_DISTANCE &&(dis[pos]+list[pos][j].distance)==dis[j] && cost[pos]+list[pos][j].price<cost[j]))
            {
                dis[j]=dis[pos]+list[pos][j].distance;
                path[j]=pos; // 更新前驱节点
                cost[j]=cost[pos]+list[pos][j].price; // 更新cost[j]                
            }
        }
    }
}

int main()
{
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            list[i][j].price=-1;
            list[i][j].distance=MAX_DISTANCE;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        list[a][b].distance=c;
        list[a][b].price=d;
        list[b][a].distance=c;
        list[b][a].price=d;
    }
    dijkstra(s);
    cout<<dis[d]<<" "<<cost[d];
    return 0;


}