#include<iostream>  
#include<climits>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;  
const int N=1001;
int graph[N][N];
int dist[N];//某点到集合的距离
int n,m,res;//n为村庄数，m为道路条数，res为最短距离
bool visited[N];//是否访问过该村庄


void prim(){
    dist[1]=0;
    visited[1]=true;
    for( int i=2;i<=n;i++){
        dist[i]=min(graph[i][1],dist[i]);//记录每一个节点到这个集合的最短距离，当前这个集合只有1节点
    }
    for(int i=2;i<=n;i++)
    {
        int tmp=INT_MAX;//初始化最短距离
        int point=-1;//记录距离集合最近的点
        for(int j=2;j<=n;j++)
        {
            if(!visited[j]&&dist[j]<tmp)
            {
                point=j;
                tmp=dist[j];
            }
        }

        if(point==-1)
        {
            res=INT_MAX;
            return;
        } 
        
        visited[point]=true;
        res+=tmp;//更新最短距离
        for(int j=2;j<=n;j++) dist[j]=min(graph[point][j],dist[j]);//更新集合中所有点到这个集合的最短距离
    }
}



int main(){
    cin>>n>>m;
    for(int i = 1 ; i<= n ;i++)
    {
        for(int j = 1; j <= n ;j++)
        {
            graph[i][j] = INT_MAX;//初始化任意两个点之间的距离为正无穷（表示这两个点之间没有边）
        }
        dist[i] = INT_MAX;//初始化所有点到集合S的距离都是正无穷
    }
    for (int i=0;i<m;i++){
        int a;int b;int c;
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    
    prim();
    if(res==INT_MAX) cout<<-1;
    else cout<<res;
    return 0;

}