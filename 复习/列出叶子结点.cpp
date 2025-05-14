#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
typedef struct TNode
{
    int left;
    int right;
}TNode;
TNode Tree[20];
int root[20];
int is_leaf[20];
vector<int> ans;

void bfs(int root)
{
    queue <int> q;
    q.push(root);
    while(q.size()!=0)
    {
        int tmp=q.front();
        q.pop();
        if(is_leaf[tmp]==1) {
            ans.push_back(tmp);
            continue;
        }  
        else
        {
            if(Tree[tmp].left!=-1) q.push(Tree[tmp].left);
            if(Tree[tmp].right!=-1) q.push(Tree[tmp].right);
        }      
    }
}


void frontSort(int root)
{
    if(is_leaf[root]==1) {
        ans.push_back(root);
        return ;
    }
    if(Tree[root].left!=-1) frontSort(Tree[root].left);
    if(Tree[root].right!=-1) frontSort(Tree[root].right);
}

int main()
{
    int n;cin>>n;
    memset(root,-1,sizeof(root));
    memset(is_leaf,0,sizeof(is_leaf));
    for(int i=0;i<n;i++)
    {
        string left,right;
        cin>>left>>right;
        if(left!="-")
        {
            Tree[i].left=stoi(left);
            root[Tree[i].left]=i;
        }else  Tree[i].left=-1;
        if (right !="-")
        {
            Tree[i].right=stoi(right);
            root[Tree[i].right]=i;
        }
        else  Tree[i].right=-1;
        if(right =="-" && left =="-")
        {
            is_leaf[i]=1;
        }
    }
    int roots;
    for(int i=0;i<n;i++)
    {
        if(root[i]==-1)
        {
            roots=i;
            break;
        }
    }
    bfs(roots);
    for(int i=0;i<ans.size();i++)
    {
        if(i==ans.size()-1) cout<<ans.at(i);
        else cout<<ans.at(i)<<" ";
    }
    return 0;
}