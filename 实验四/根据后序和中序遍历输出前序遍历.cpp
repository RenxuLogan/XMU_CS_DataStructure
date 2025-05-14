#include<iostream>
#include<vector>
using namespace std;
const int max_size=30;
int PostOrder[max_size];
int InOrder[max_size];
vector<int> PreOrder;
int n;


void  pre(int root,int start,int end){
    if(start>end){
        return ;
    }
    int i=start;
    while(i<end && InOrder[i]!=PostOrder[root]){
        i++;
    }
    PreOrder.push_back(PostOrder[root]);//root
    pre(root-1-(end-i),start,i-1);//left
    pre(root-1,i+1,end);//right
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>PostOrder[i];
    }
    for(int i=0;i<n;i++){
        cin>>InOrder[i];
    }
    pre(n-1,0,n-1);
    // output
    cout<<"Preorder: ";
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<PreOrder[i];
        }else{
            cout<<PreOrder[i]<<" ";
        }
    }
    return 0;
}