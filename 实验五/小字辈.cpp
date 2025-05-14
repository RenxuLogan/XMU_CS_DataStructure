#include<iostream>
#include<queue>
using namespace std;
const int N=100001;
int a[N];
int bf[N];
int n,root;
int res;
queue<int> q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){ 
        cin>>a[i];
        if(a[i]==-1){
            root=i;
            bf[i]=1;
        }
    }
    q.push(root);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int son;
        for(int i=1;i<=n;i++){
            if(a[i]==u){
                son=i;
                bf[son]=bf[u]+1;
                res=max(res,bf[son]);
                q.push(son);
            }
        }
    }
    cout<<res<<endl;
    queue<int> ans;
    for(int i=1;i<=n;i++){
        if(bf[i]==res){
            ans.push(i);
        }
    }
    while(!ans.empty()){
        if(ans.size()!=1){
            cout<<ans.front()<<" ";
        }else{
            cout<<ans.front()<<endl;
        }
        ans.pop();
    }
    return 0;  
}