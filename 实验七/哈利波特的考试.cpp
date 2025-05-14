#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
#define MAX_SIZE 100
#define MAX_DISTANCE 1e6

int n,m;
int graph[MAX_SIZE][MAX_SIZE];

inline int dijkstra(int start)
{
    int dis[MAX_SIZE]={0};
    int vis[MAX_SIZE]={0};
    int res=-1;

    for(int i=1;i<=n;i++)
    {
        dis[i]=graph[start][i];
    }
    vis[start]=1;

    for(int i=1;i<=n;i++)
    {
        int min=MAX_DISTANCE+1;
        int pos=-1;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==0 && dis[j]<min)
            {
                min=dis[j];
                pos=j;
            }
        }
        if(pos==-1) {
            return -1;
        }
        vis[pos]=1;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==0 && graph[pos][j]< MAX_DISTANCE )
            {
                dis[j] = dis[j] >dis[pos] + graph[pos][j]? (dis[pos] + graph[pos][j]):dis[j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            return -1;
        }
        res=max(res,dis[i]);
    }
    return res;

}


int main()
{
    memset(graph,MAX_DISTANCE,sizeof(graph));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,len;
        cin>>a>>b>>len;
        graph[a][b]=len;
         graph[b][a]=len;
    }
    int ans=INT_MAX;int min_start=-1;
    for(int i=1;i<=n;i++)
    {
        int tmp=dijkstra(i);
        if(tmp!=-1 && tmp<ans ){
            ans=tmp;
            min_start=i;
        }
    }
    if(min_start==-1)cout<<0;
    else cout<<min_start<<" "<<ans;
    return 0;
}