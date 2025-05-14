#include<iostream>
#include<cstring>
using namespace std;
int graph[15][15];
int visited[15];
void dfs(int node,int target,int n)
{
    visited[node]=1;
 
    
        for(int i=0;i<n;i++)
        {
            if(visited[i]== 0 && graph[node][i]==1) dfs(i,target,n);
        }
    
}



int main()
{
    int n,e;
    cin>>n>>e;
    memset(graph,0,15*15*sizeof(int));
    for(int i=0;i<e;i++)
    {
        int a,b;cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int start,target;
    cin>>start>>target;
    memset(visited,0,15*sizeof(int));
    dfs(start,target,n);
    if(visited[target]==1)
    {
        cout<<"There is a path between "<<start<<" and "<<target<<".";
    }
    else {
        cout<<"There is no path between "<<start<<" and "<<target<<".";
    }
    return 0;
}