#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    while(k){
        queue<int>q;
        int temp=0;
        stack<int> box;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            q.push(x);
        }

        while ( true ){
            if(temp==n){
                cout<<"YES"<<endl;
                break;
            }
            if(box.size()>m){
                cout<<"NO"<<endl;
                break;
            }
            if(!q.empty()&& q.front() == temp+1){
                q.pop();
                temp++;
            }else if(!box.empty()&&box.top()==temp+1){
                box.pop();
                temp++;
            }else{
                if(q.empty()){
                    cout<<"NO"<<endl;
                    break;
                }else{
                    box.push(q.front());
                    q.pop();
                }
            }
        }
        k--;
    }
    return 0;

}