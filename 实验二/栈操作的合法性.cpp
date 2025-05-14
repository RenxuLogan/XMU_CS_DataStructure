#include<iostream>
#include<string>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    while(n){
        string s;
        int top=-1;
        cin>>s;
        int flag=0;
        for(int i=0;i<s.size()&&flag==0;i++){
            if(s[i] =='S'){
                top++;
            }else{
                top--;
            }
            if(top<-1 || top>=m){
                flag=1;
            }
        }
        if(flag || top!=-1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        n--;
    }

    return 0;
}