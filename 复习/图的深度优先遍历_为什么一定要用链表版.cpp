#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);  // 升序排序
}
int graph[20000][51];
//qsort的使用和利用哨兵+数组的方式实现邻接表的书写方法
void dfs(int visited[],int node,int n)
{
    visited[node]=1;
    cout<<node<<" ";
    for(int i=1 ;i<=graph[node][0];i++)
    {
        if(visited[ graph[node][i] ]==0 ) dfs(visited,graph[node][i],n);
    }
}
void dfs_picture(int n)
{
    int visited[20000];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 ) dfs(visited,i,n);//等于0说明是孤立顶点也要输出的哈！！
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        memset(graph[i],0,sizeof(graph[i]));
    }
    for(int i=0;i<e;i++)
    {
        int start,end;cin>>start>>end;
        graph[start][ ++graph[start][0] ]=end;
    }
    for(int i=0;i<n;i++) qsort(&graph[i][1],graph[i][0],sizeof(int),cmp );
    dfs_picture(n);
    return 0;
}