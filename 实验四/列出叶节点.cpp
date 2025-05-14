#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#include<string>
using namespace std;
int  n;
const int max_size=10;
int find_root[max_size];
typedef pair<int,int> TreeNode;
TreeNode tree[max_size];
int root;
queue <int> res;
void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        int l,r;
        l=tree[temp].first;
        r=tree[temp].second;
        if(l==-1&&r==-1){
            res.push(temp);
        }else{
            if(l!=-1) q.push(l);
            if(r!=-1) q.push(r);
        }

    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string tl,tr;
        cin>>tl>>tr;
        if(tl!="-"){
            int x=stod(tl);
            find_root[x]=1;
            tree[i].first=stod(tl);
        }else{
            tree[i].first=-1;
        }
        if(tr!="-"){
            int x=stod(tr);
            find_root[x]=1;
            tree[i].second=stod(tr);
        }else{
            tree[i].second=-1;
        }
    }
    for(int i=0;i<n;i++){
        if(find_root[i]==0){
            root=i;
            break;
        }
    }
    bfs(root);
    while(!res.empty()){
        cout<<res.front();
        res.pop();
        if(!res.empty()) cout<<" ";
    }
    return 0;


}