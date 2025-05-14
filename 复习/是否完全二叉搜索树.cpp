#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
}TNode;
void InsertNode(TNode *root,int value)
{
    TNode *new_node = new TNode;
    new_node->left=nullptr;
    new_node->right=nullptr;
    new_node->data=value;
    TNode* tmp = root;
    while( 1)
    {
        while(tmp->data < value && tmp->left != nullptr)
        {
            tmp=tmp->left;
        } 
        if(tmp->data < value && tmp->left == nullptr)
        {
            tmp->left=new_node;
            break;
        }
        while(tmp->data > value && tmp->right != nullptr)
        {
            tmp=tmp->right;
        } 
        if(tmp->data > value && tmp->right == nullptr)
        {
            tmp->right=new_node;
            break;
        }
    }
    return ;
}


int main()
{
    int n;cin>>n;
    TNode * root = new TNode;
    cin>>root->data;
    for(int i=1;i<n;i++)
    {
        int input;
        cin>>input;
        InsertNode(root,input);
    }
    queue<TNode *> q;
    vector<int> v;
    q.push(root);
    int flag_for_queue=0;
    int flag_for_ans=1;

    while(q.size()!=0)
    {
        TNode * current = q.front();
        v.push_back(current->data);
        q.pop();
        if(current->left!=nullptr)
        {
            if(flag_for_queue==1) flag_for_ans=0;
            q.push(current->left);
        }else flag_for_queue=1;
        if(current->right!=nullptr)
        {
            if(flag_for_queue==1) flag_for_ans=0;
            q.push(current->right);
        }else flag_for_queue=1;        
    }
    for(int i=0;i<n;i++)
    {
        if(i!=n-1) cout<< v.at(i)<<" ";
        else cout<<v.at(i)<<endl;
    }
    if(flag_for_ans==0) cout<<"NO";
    else cout<<"YES";
    return 0;
}