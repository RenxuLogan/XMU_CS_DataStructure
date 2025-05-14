#include<iostream>
#include<queue>
using namespace std;
int N;
int main(){
    cin>>N;
    queue<int> a;
    queue<int> b;
    queue<int> result;
    while(N--){
        int x;
        cin>>x;
        if(x%2==1) a.push(x);
        else b.push(x);
    }
    while(a.size() >= 2 && !b.empty()){
        result.push(a.front());
        a.pop();
        result.push(a.front());
        a.pop();
        result.push(b.front());
        b.pop();
    }
    while(!a.empty()){
        result.push(a.front());
        a.pop();
    }
    while(!b.empty()){
        result.push(b.front());
        b.pop();
    }
    while(!result.empty()){
        cout<<result.front();
        result.pop();
        if(!result.empty()) cout<<" ";
    }
    return 0;
}