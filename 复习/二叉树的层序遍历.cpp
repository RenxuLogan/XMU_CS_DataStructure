#include<iostream>
#include<queue>

using namespace std;
typedef struct TNode
{
    int data;
    struct TNode * left;
    struct TNode * right; 
}TNode;

int LastOrder[35];
TNode *gengerate(int root,int start ,int end)
{
    if(end<=start ) return nullptr;
    TNode * tmp = new TNode;
    tmp->data = LastOrder[root];
    tmp->left = gengerate(root/2,start ,root/2);
    tmp->right= gengerate(root-1, root/2+1 ,root-1);
    return tmp;
}



int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>LastOrder[i];
    TNode * root = new TNode;
    root = gengerate(n-1,0,n-1);
    queue<TNode*> q;
    int ans[35];
    int ans_index=0;
    q.push(root);
    ans[ans_index++]=root->data;
    while(q.size()!=0)
    {
        TNode * tmp= q.front();
        q.pop();
        if(tmp->left!=nullptr)
        {
            q.push(tmp->left);
            ans[ans_index++]=tmp->left->data;
        }
        if(tmp->right!=nullptr)
        {
            q.push(tmp->right);
            ans[ans_index++]=tmp->right->data;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)cout<<ans[i]<<" ";
        else cout<<ans[i];
    }
    return 0;


}