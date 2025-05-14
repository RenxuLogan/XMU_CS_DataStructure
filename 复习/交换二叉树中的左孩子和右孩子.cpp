#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct TNode
{
    char data;
    struct TNode * left;
    struct TNode * right;
}TNode;

int idx=0;
string input;

TNode* PreOrder()
{
    if(input[idx]=='#' || idx>=input.size()) 
    {
        idx++;
        return nullptr;
    }
    TNode * new_node = new TNode;
    new_node->data=input[idx++];
    new_node->left=PreOrder();
    new_node->right=PreOrder();
    return new_node;
}
vector <char> Inorder;
void InOrder(TNode * root)
{
    if(root->left != nullptr) InOrder(root->left);
    Inorder.push_back(root->data);
    if(root->right != nullptr) InOrder(root->right);
}

void Myswap(TNode * root)
{
    if(root == nullptr) return ;
    swap(root->left,root->right);
    Myswap(root->left);
    Myswap(root->right);
}

int main()
{
    cin >> input;
    TNode *root = new TNode ;
    root = PreOrder();
    InOrder(root);
    for(int i =0 ;i<Inorder.size();i++)
    {
        if(i==Inorder.size()-1) cout<<Inorder.at(i)<<endl;
        else cout<<Inorder.at(i);
    } 
    idx=0;
    Myswap(root);
    Inorder.clear();
    InOrder(root);
    for(int i =0 ;i<Inorder.size();i++)
    {
        if(i==Inorder.size()-1) cout<<Inorder.at(i)<<endl;
        else cout<<Inorder.at(i);
    } 
    return 0;
}