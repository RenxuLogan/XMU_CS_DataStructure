#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef struct node{
    char data;
    struct node *left, *right;
}TreeNode;
string s;
int pos=0;

TreeNode* CreateTree(){

    if(pos >= s.size()) return nullptr;
    if(s[pos]=='#') {
        pos++;
        return nullptr;
    }
    TreeNode *root = new TreeNode();
    root->data = s[pos++];
    root->left=CreateTree();
    root->right=CreateTree();
    return root;
}

void InOrder(TreeNode *root){
    if(root == nullptr ) return;
    InOrder(root->left);
    cout << root->data;
    InOrder(root->right);
}
void change(TreeNode *root){
    if(root==nullptr) return;
    swap(root->left, root->right);
    change(root->left);
    change(root->right);
}


int main(){
    cin >> s;
    TreeNode *root=CreateTree();
    InOrder(root);
    cout<<endl;
    change(root);
    InOrder(root);
    return 0;


}