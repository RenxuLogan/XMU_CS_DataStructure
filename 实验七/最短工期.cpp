#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX_SIZE 100
#define MAX_TIME 1e6

int graph[MAX_SIZE][MAX_SIZE];
int n,m;
int in[MAX_SIZE];       //入度
int print[MAX_SIZE];
int ans;
int dis[MAX_SIZE]; //最早完成时间


int TopologicalSort()
{
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(in[i]==0)
        {
            v.push_back(i);
        }
    }

    int index=0;
    while(v.size())
    {
        
        int current= v.back();
        print[index++]=current;
        v.pop_back();
        for(int i=0;i<n;i++)
        {
            if( graph[current][i]!= MAX_TIME)
            {
                if(--in[i]==0)
                {
                    v.push_back(i);
                }
                dis[i]=max(dis[i],dis[current]+graph[current][i]);
                ans=max(ans,dis[i]);
            }
        }
    }
    if(index!= n)
    {
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=MAX_TIME;
        }
    }

    for(int i=0 ;i<m;i++)
    {
        int a,b,t;
        cin>>a>>b>>t;
        graph[a][b]=min(graph[a][b],t);
        in[b]++;    //入度++
    }
    if(TopologicalSort()==1) cout<<ans;
    else cout<<"Impossible";
    return 0;



}