#include<iostream>
#include<cmath>
using namespace std;
const int max_size=1001;
int tree[max_size];
int n,i,j;

int main(){
    cin>>n;
    for(int i=1;i<n+1;i++){
        cin>>tree[i];
    }
    cin>>i>>j;
    if(tree[i]==0){
       cout<<"ERROR: T["<<i<<"] is NULL";
       exit(EXIT_SUCCESS);
    }
    if(tree[j]==0){
        cout<<"ERROR: T["<<j<<"] is NULL";
        exit(EXIT_SUCCESS);
    }
    int pre1=i;
    int pre2=j;
    while(pre1>0&&pre2>0){
        if(pre1<pre2){
            pre2=floor(pre2/2);
        }else if(pre2<pre1){
            pre1=floor(pre1/2);
        }
        if(pre1==pre2){
            break;
        } 
    }
    cout<<pre1<<" "<<tree[pre1];
    return 0;
}