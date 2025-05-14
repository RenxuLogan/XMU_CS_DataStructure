#include<iostream>
#include<cstring>
using namespace std;

typedef struct linkNode
{
    int data;
    struct linkNode* next;
}linkNode;

typedef struct LinkList
{
    linkNode* list[20000];
    int n;
}LinkList;

void insert(LinkList* l,int start,int end)
{
    linkNode* node = new linkNode;
    node->data=end;
    node->next=nullptr;
    if(l->list[start]->next==nullptr)
    {
        l->list[start]->next=node;
    }
    else
    {
        linkNode * pre=l->list[start] ;
        linkNode * current = l->list[start]->next;

        while(current!=nullptr && current->data < node->data)
        {
            pre=current;
            current = current->next;
        }
        pre->next=node;
        node->next=current;
    }
}
void dfs(int visited[],linkNode* node,LinkList* l)
{
    visited[node->data]=1;
    cout<<node->data<<" ";
    while(node->next!=nullptr)
    {
        node=node->next;
        if(visited[node->data]==0) 
        {
            dfs(visited,node,l);
        }
    }
}
void dfs_picture(LinkList* l)
{
    int visited[20000];
    for(int i=0;i<l->n;i++) visited[i]=0;
    
    for(int i=0;i<l->n;i++)
    {
        if(l->list[i]->next!=nullptr && visited[i]==0)
        {
            dfs(visited,l->list[i],l);
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    LinkList* l = new LinkList;
    for (int i = 0; i < n; i++)
    {
        l->list[i] = new linkNode;  // 为每个节点分配内存
        l->list[i]->next = nullptr; // 初始化链表为空
        l->list[i]->data = i;
    }
    l->n=n;
    for(int i=0;i<e;i++)
    {
        int start , end;
        cin>>start >> end;
        insert(l,start,end);
    }
    dfs_picture(l);
    return 0;
}