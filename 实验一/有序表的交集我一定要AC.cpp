#include<iostream>
#include<queue>
using namespace std;
void print_queue(const queue<int> &q){
    queue<int> q2 = q;
    while(q2.size()>1){
        cout<<q2.front()<<" ";
        q2.pop();
    }
    if(q2.size()>0){
        cout<<q2.front();
    }
}
int main(){
    queue<int> q1;
    queue<int> q2;
    while(true){
        int x;
        cin>>x;
        if(x==-1) break;
        q1.push(x);
    }
    while(true){
        int x;
        cin>>x;
        if(x==-1) break;
        q2.push(x);
    }
    queue<int> ans;
    while(! q1.empty()&& ! q2.empty()){
        if(q1.front()==q2.front()){
            ans.push(q1.front());
            q1.pop();
            q2.pop();
        }else if(q1.front()>q2.front()){
            q2.pop();
        }else if(q1.front()<q2.front()){
            q1.pop();
        }
    }
    if(ans.size()>0){
        print_queue(ans);
    }else{
        cout<<"NULL";
    }
    return 0;
}