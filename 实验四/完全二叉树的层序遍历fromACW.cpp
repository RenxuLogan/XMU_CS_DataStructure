#include<iostream>
#include<vector>
using namespace std;
const int max_size=31;
int PostOrder[max_size];
int res[max_size];
int n;
int idx;

void postorder(int root){
    if(root>n){
        return ;
    }
    postorder(root*2);
    postorder(root*2+1);
    res[root]=PostOrder[idx++];
}



int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>PostOrder[i];
    }
    postorder(1);
    for(int i=1;i<=n;i++){
        if(i!=n) cout<<res[i]<<" ";
        else cout<<res[i];
    }
    return 0;
}