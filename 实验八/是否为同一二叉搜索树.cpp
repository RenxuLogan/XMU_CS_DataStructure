#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
using namespace std;
typedef struct TreeNode
{
    int value;
    TreeNode * left;
    TreeNode * right;
    bool flag;
}TreeNode;

void my_insert(TreeNode *root,int v)
{
    TreeNode *parent= root;
    while(root != nullptr)
    {
        if(v > root->value) 
        {
            parent= root;
            root = root->right;
        }
        else 
        {
            parent= root;
            root = root->left;
        }
    }
    TreeNode* New = new TreeNode;
    New->value=v;
    New->flag=false;
    New->left=nullptr;
    New->right=nullptr;
    if(v>parent->value) parent->right=New;
    else parent->left =New;
    return ;
}


TreeNode * creat_tree(int array[],int N)
{
    TreeNode *root =new TreeNode;
    root->value=array[0];
    root->right = nullptr;
    root->left  = nullptr;
    root->flag  = false;
    for(int i=1;i<N;i++)
    {
        my_insert(root,array[i]);
    }

    return root;
}


bool cmp(TreeNode *root,int v)
{
    if(root==nullptr) return false;
    bool flag;
    if(root->flag)
    {
        if(root->value < v) flag = cmp(root->right,v);
        else flag=cmp(root->left , v);
    }
    else
    {
        if(root->value == v)
        {
            root->flag = true;
            flag=true;
        }
        else
        {
            flag=false;
        }
    }
    return flag;
}

void reset (TreeNode * root)
{
    if(root==nullptr) return ;
    root->flag=false;
    reset(root->left);
    reset(root->right);
}

void free(TreeNode * root)
{
    if(root)
    {
        free(root->right);
        free(root->left);
        delete root;
    }
}



int main() {
    int N;
    scanf("%d", &N);
    while (N != 0) {
        int L;
        scanf("%d", &L);

        int array[15];
        for (int i = 0; i < N; i++) scanf("%d", &array[i]);

        TreeNode *root = creat_tree(array, N);

        for (int i = 0; i < L; i++) {
            bool flag = true;
            for (int j = 0; j < N; j++) {
                int v;
                scanf("%d", &v);
                if (!cmp(root, v)) {
                    flag = false;
                }
            }
            printf("%s\n", flag ? "Yes" : "No");
            reset(root);  // 重置访问标记
        }

        free(root);  // 释放树内存
        scanf("%d", &N);
    }
    return 0;
}