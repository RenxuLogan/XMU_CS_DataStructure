#include<iostream>
#include<map>
#include<utility>
using namespace std;

int main(){
    int row,col,t;
    cin>>row>>col>>t;
    map<pair<int ,int>,int> m;
    for(int i=0;i<t;i++){
        int x,y,v;
        cin>>y>>x>>v;
        m[{x,y}]=v;
    }
    for(const auto& entry : m){
        cout<<entry.first.first<<" "<<entry.first.second<<" "<<entry.second<<endl;
    }
    return 0;
}