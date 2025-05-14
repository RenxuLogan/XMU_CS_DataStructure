#include <iostream>
#include <queue>
#include <climits>

using namespace std;
#define MAX_SIZE 100
int list[MAX_SIZE][MAX_SIZE];
int vis[MAX_SIZE];
int n,m;
int ans=0;
void prim(){
    vis[0]=1;
    int dis[MAX_SIZE];
    for(int i=1;i<n;i++)
    {
        dis[i]=list[0][i];
    }
    for(int i=1;i<n;i++)
    {
        int min=INT_MAX;
        int pos=-1;

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
            break;
            ans=-1;
        }
        
        vis[pos]=1;
        ans+=min;
        for(int j=0;j<n;j++)
        {
            if(list[pos][j]<dis[j])
            {
                dis[j]=list[pos][j];
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
            list[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,t;
        cin>>a>>b>>t;
        list[a][b]=t;
    }
    prim();
    if(ans!=-1)
    {
        cout<<ans;
    }else{
        cout<<"Impossible";
    }
    return 0;
}