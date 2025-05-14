#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int max_size=30;
int PostOrder[max_size];
int InOrder[max_size];
vector<int> res;

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

TreeNode* RebuildTree(int root,int start,int end){
    if(start>end){
        return nullptr;//空指针
    }
    TreeNode* node = new TreeNode(PostOrder[root]);
    int i=start;
    while(i<end && InOrder[i]!=PostOrder[root]) i++;
    node->left=RebuildTree(root-1-(end-i),start,i-1);
    node->right=RebuildTree(root-1,i+1,end);
    return node;
}
void bfs(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left!=nullptr) q.push(node->left);
        if(node->right!=nullptr) q.push(node->right);
        res.push_back(node->val);
    }
    return ;
}


int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>PostOrder[i];
    }
    for(int i=0;i<n;i++){
        cin>>InOrder[i];
    }   
    TreeNode* root=RebuildTree(n-1,0,n-1);
    bfs(root);
    for(int i=0;i<n;i++){
        if(i!=n-1){
            cout<<res[i]<<' ';
        }else{
            cout<<res[i];
        }
    }
    return 0;
}