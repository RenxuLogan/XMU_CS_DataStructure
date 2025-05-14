#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int graph[15][15];

void DFS(int visited[],int node,int n)
{
    visited[node]=1;
    cout<<node<<" ";
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && graph[node][i]==1)
        {
            DFS(visited,i,n);
        }
    }

}



void DFS_picture(int n)
{
    int visited[15];
    for(int i=0;i<15;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i]) 
        {
            cout<<"{ ";
            DFS(visited,i,n);
            cout<<"}"<<endl;
        }
    }
}
void BFS(int n)
{
    int visited[15];
    for(int i=0;i<15;i++)
    {
        visited[i]=0;
    }
    queue <int> q;
    for(int i= 0;i<n;i++)
    {
        if(visited[i]==0)
        {
            cout<<"{ ";
            q.push(i);
            visited[i]=1;
            while(q.size()!=0)
            {
                int node = q.front();
                q.pop();
                cout<<node<<" ";
                for(int j = 0;j<n;j++)
                {
                    if(visited[j]==0 && graph[node][j]==1)
                    {
                        q.push(j);
                        visited[j]=1;//广搜已访问的节点一定要在这里进行标记，否则下一个进来的节点如果还是与j相关的j就会重复入队！！！
                    }
                }
            }
            cout<<"}"<<endl;
        }
    }
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    DFS_picture(n);
    BFS(n);
}