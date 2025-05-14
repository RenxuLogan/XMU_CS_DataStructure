#include <iostream>
#define MAX 10000
using namespace std;
#define MAX_SIZE 100
int list[MAX_SIZE][MAX_SIZE];
int m,n;
int dis[MAX_SIZE];
int path[MAX_SIZE];
int vis[MAX_SIZE];




void dijkstra(int start)
{
    vis[start]=1;
    path[start]=-1;
    for(int i=0;i<n;i++)
    {
        dis[i]=list[start][i];
        path[i]=start;
    }
    for(int i=0;i<n;i++)
    {
        int pos=-1;
        int min=MAX+1;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==0 && dis[j]<min)
            {
                pos=j;
                min=dis[j];
            }
        }

        if(pos==-1) break;
        vis[pos]=1;

        for(int j=0;j<n;j++){
            if(vis[j]==0&& dis[j]>dis[pos]+list[pos][j])
            {
                dis[j]=dis[pos]+list[pos][j];
                path[j]=pos;
            }
        }
    }
}



int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            list[i][j]=MAX;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,t;
        cin>>a>>b>>t;
        list[a][b]=t;
    }
    dijkstra(0);
    int count=0;
    int index=n-1;
    while(index!=0)
    {
        cout<<index<<"<-";

        index=path[index];
    }
    /*    
    for(int i=0;i<n;i++)
    {
        if(vis[i]==1) count++;
    }
    if(count ==n)
    {
        cout<<dis[n-1];
    }else{
        cout<<"Impossible";
    }
    */
    return 0;
}