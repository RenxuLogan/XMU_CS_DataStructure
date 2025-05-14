#include<iostream>
using namespace std;
typedef struct TNode
{
    int flag = 0;
    int data;
    struct  TNode * left;
    struct  TNode * right;
}TNode;

void resetTree(TNode *root)
{
    if(root==nullptr) return ;
    root->flag = 0;
    resetTree(root->left);
    resetTree(root->right);
}
void freeT(TNode *root)
{
    if(root == nullptr) return ;
    freeT(root->left);
    freeT(root->right);
    delete root;
}
void Insert(TNode *root,int value)
{
    TNode * pre=root;
    TNode *new_node =new TNode;
    new_node->data = value;
    new_node->left=nullptr;
    new_node->right=nullptr;
    while(root!=nullptr)
    {
        pre=root;
        if(root->data > value) 
        {
            root=root->left;
        }
        else
        {
            root = root->right;
        } 
    }
    if(value > pre->data)  pre->right = new_node;
    else pre->left = new_node;

}

TNode* create_Tree(int a[],int n)
{
    TNode * tmp =new TNode;
    tmp->left  = nullptr;
    tmp->right = nullptr;
    tmp->data =a[0];
    for(int i = 1;i<n;i++) Insert(tmp,a[i]);
    return tmp;
}

int cmp(TNode *roots,int a[],int n)
{
    int flag = 1;
    for(int i = 0;i<n;i++)
    {
        TNode * root =roots;
        int tmp=a[i];
        while(tmp != root->data && root->flag == 1)
        {
            if(tmp>root->data)
            {
                root=root->right;
            }
            else 
            {
                root=root->left;
            }
        }
        if(root->data!=tmp || (root->data==tmp && root->flag == 1))
        {
            flag=0;break;
        }
        root->flag = 1;
    }
    return flag;
}
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        int L;cin>>L;
        int a[15];
        for(int i=0;i<n;i++) cin>>a[i];
        TNode * root= create_Tree(a,n);
        for(int i = 0;i<L;i++)
        {
            resetTree(root); 
            int tmp[15];
            for(int j=0;j<n;j++) cin>>tmp[j];
            int flag = cmp(root,tmp,n);
            if(flag == 1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        free(root);
        cin>>n;
    }
    return 0;
}