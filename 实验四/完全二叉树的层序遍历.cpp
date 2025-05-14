#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int max_size =30;
int PostOrder[max_size];
int n;
typedef struct TreeNode{
    int val;
    struct TreeNode *left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

TreeNode* RebuildTree(int root,int start,int end){
   if(start>end){
    return nullptr;
   }
    TreeNode* node = new TreeNode(PostOrder[root]);


    
    return node;
}
void bfs(TreeNode *root){


}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>PostOrder[i];
    }
    TreeNode * root=RebuildTree(n-1,)
    
}