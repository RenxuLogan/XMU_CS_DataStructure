#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N =100001;
vector<int> children[N];
queue <int> q;
int bf[N];
int root,res,n;

int main(){
    cin>>n;
    res=1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==-1) root=i;
        else children[x].push_back(i);
    }
    q.push(root);
    bf[root]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i:children[u]){
            q.push(i);
            bf[i]=bf[u]+1;
            if(bf[i]>res) {
                res=bf[i];
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
        if(ans.size()==1){
            cout<<ans.front()<<endl;
            ans.pop();
        }else{
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }

    return 0;
}