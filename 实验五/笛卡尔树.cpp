#include<iostream>
#include<queue>
#include<utility>
using namespace std;
const int max_size=1001;
pair<pair<int,int> ,pair<int,int> > tree[max_size];
int in[max_size];
int InorderIndex=0;
bool isHeap=true;
int root=-1;
int isRoot[max_size];


void Inorder(int i,int l,int r){
    if(i == -1){
        return ;
    }
    Inorder(l,tree[l].second.first,tree[l].second.second);
    in[InorderIndex++]=tree[i].first.first;
    Inorder(r,tree[r].second.first,tree[r].second.second);
}
void checkHeap(int i){
    if(i==-1) return ;
    int l=tree[i].second.first;
    int r=tree[i].second.second;
    if (l != -1 && tree[i].first.second > tree[l].first.second) {
        isHeap = false;
    }
    if (r != -1 && tree[i].first.second > tree[r].first.second) {
        isHeap = false;
    }
    checkHeap(l);
    checkHeap(r);
}
//下标是k1，节点的值是k2
int main (){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x,v,l,r;
        cin>>x>>v>>l>>r;
        tree[i].first.first=x;
        tree[i].first.second=v;
        tree[i].second.first=l;
        tree[i].second.second=r;
        isRoot[l]=1;
        isRoot[r]=1;
    }
    for(int i=0;i<n;i++){
        if(isRoot[i]==0){
            root=i;
            break;
        }
    }
    Inorder(root,tree[root].second.first,tree[root].second.second);
    checkHeap(root);
    int flag1=0;
    for(int i=1;i<n;i++){
        if(in[i]<in[i-1]){
            flag1=1;
            break;
        }
    }
    if(flag1==0 && isHeap){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}