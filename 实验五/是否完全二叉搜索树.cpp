#include<iostream>
#include<queue>

using namespace std;
const int max_size=21;
int a[max_size];
int n,i,j;
int Inorder[max_size];

typedef struct tree{
    int val;
    struct tree *left,*right;
}tree;

queue< tree* > q;

void InOrder(tree* root){
    if(root==NULL) return ;
    InOrder(root->left);
    Inorder[j++]=root->val;
    InOrder(root->right);
}
void bfs_build(tree* root){
    root->val=a[i++];
    q.push(root);
    while(!q.empty()){
        tree *p=q.front();
        q.pop();
        if(i<n){
            tree *left=new tree;
            left->val=a[i++];
            p->left=left;
            q.push(left);
        }
        if(i<n){
            tree *right=new tree;
            right->val=a[i++];
            p->right=right;
            q.push(right);
        }
    }

    return ;

}



int main(){
    int flag=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    tree *root=new tree;
    bfs_build(root);
    InOrder(root);
    for(int i=0;i<n-1;i++)
        if(Inorder[i]>Inorder[i+1]){
            flag=1;
            break;
        }

    if(!flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;


}