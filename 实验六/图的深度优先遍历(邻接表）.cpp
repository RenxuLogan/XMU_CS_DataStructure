#include<iostream>

using namespace std;
#define MAX_NODE 20000

typedef struct EdgeNode
{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VNode
{
    int data;
    EdgeNode *firstedge;
}VNode,AdjList[MAX_NODE];
//顶点表

typedef struct Graph
{
    AdjList adjlist;
    int Node_num, Edge_num;
}Graph;
//表+节点树和边数
Graph g;
int visited[MAX_NODE];



void dfs(int start){
    visited[start]=1;
    cout << g.adjlist[start].data << " ";
    for(EdgeNode *p=g.adjlist[start].firstedge;p!=NULL;p=p->next)
    {
        if(visited[p->adjvex]==0)
        {
            dfs(p->adjvex);
        }
    }
    return ;
}

void dfs_graph(){
    for(int i=0;i<g.Node_num;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    return ;
}
int main(){
    int n,e;
    cin>>n>>e;
    g.Node_num=n;
    g.Edge_num=e;
    for(int i=0;i<n;i++){
        g.adjlist[i].firstedge=NULL;
        g.adjlist[i].data=i;
    }
    for(int i=0;i<e;i++)
    {
        int a;int b;
        cin>>a>>b;
        EdgeNode *p=new EdgeNode;
        p->next=NULL;
        p->adjvex=b;

        EdgeNode *q=new EdgeNode;
        q=g.adjlist[a].firstedge;

        EdgeNode *pre=new EdgeNode;
        pre=NULL;

        while(q!=NULL && q->adjvex<b)
        {
            pre=q;
            q=q->next;
        }
        if(q==g.adjlist[a].firstedge)
        {
            p->next=g.adjlist[a].firstedge;
            g.adjlist[a].firstedge=p; 
        }else{
            p->next=q;
            pre->next=p;
        }
    }
    //头插法初始化链表
    dfs_graph();
    return 0;
}