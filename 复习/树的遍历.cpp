#include<iostream>
#include<queue>
using namespace std;
typedef struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
}TNode;
int InOrder[35];
int LastOrder[35];
TNode * gengerate(int start,int end,int Lindex)
{
    if(start > end) return nullptr;
    int Iindex=start;
    for(;Iindex<=end;Iindex++)
    {
        if(LastOrder[Lindex]==InOrder[Iindex]) break;
    }
    TNode*tmp =new TNode;
    tmp->data=LastOrder[Lindex];
    tmp->left=gengerate(start , Iindex-1 , Lindex-end+Iindex-1);
    tmp->right=gengerate(Iindex+1,end,Lindex-1);
    return tmp;
}

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>LastOrder[i];
    for(int i=0;i<n;i++) cin>>InOrder[i];
    TNode * root = gengerate(0,n-1,n-1);
    queue <TNode*> q;
    q.push(root);
    int ans[35];
    int index_bfs=0;
    ans[index_bfs++] = root->data;
    while(q.size()!=0)
    {
        TNode * tmp = q.front();
        q.pop();
        if(tmp->left!= nullptr)
        {
            ans[index_bfs++] = tmp->left->data;
            q.push(tmp->left);
        }
        if(tmp->right!= nullptr)
        {
            ans[index_bfs++] = tmp->right->data;
            q.push(tmp->right);
        }
    }
    for(int i=0;i<n;i++) 
    {
        if (i==n-1) cout<<ans[i];
        else cout<<ans[i]<<" ";
    }
    return 0;
}