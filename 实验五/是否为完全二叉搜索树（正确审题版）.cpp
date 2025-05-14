#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
const int N=21;
int a[10000];
int i,n;
typedef struct TreeNode{
    int val;
    struct TreeNode *left ;
    struct TreeNode *right;
}TreeNode;
TreeNode * root=new TreeNode();

void insert (int key){
    TreeNode *temp=root;
    TreeNode *pre=NULL;
    while(temp!=NULL){
        pre=temp;
        if(temp->val<key){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }

    if(key>pre->val){
        pre->left=new TreeNode;
        pre->left->val=key;
        pre->left->right=NULL;
        pre->left->left=NULL;
    }else{
        pre->right=new TreeNode;
        pre->right->val=key;
        pre->right->left=NULL;
        pre->right->right=NULL;
    }
}

void bfs(TreeNode *root){
    queue<TreeNode*>q;
    q.push(root);
    a[i++]=root->val;
    while(!q.empty()){
        TreeNode *node=q.front();
        q.pop();
        if(node->left!=NULL){
            q.push(node->left);
            a[i++]=node->left->val;
        }else{
            a[i++]=-1;
        }
        if(node->right!=NULL){
            q.push(node->right);
            a[i++]=node->right->val;
        }else{
            a[i++]=-1;
        }
    }
}


int main(){
    cin>>n;
    int root_value;
    cin>>root_value;
    root->val=root_value;
    root->left=NULL;
    root->right=NULL;
    for(int i=1;i<n;i++) {
        int x;
        cin >> x;
        insert(x);
    }
    bfs(root);
    int count=0;
    int flag1=0;
    int flag2=0;
    for(int j=0;j<i;j++){
        if(a[j]==-1){
            flag1=1;
            continue;
        }else{
            count++;
            if(count!=n){
                cout<<a[j]<<" ";
            }else{
                cout<<a[j];
            }
            if(flag1==1){
                flag2=1;
            }
        }
    }
    cout<<endl;
    if(flag2==1){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
    return 0;
}
