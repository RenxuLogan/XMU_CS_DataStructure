#include<iostream>
#include<queue>

using namespace std;

const int N = 1010;
bool st[N];
int n,m;
int main(){
    cin>>m>>n;
    queue<int> q;
    int count=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(st[x]==false){
            count++;
        }
        if(q.size()>=m && st[x]==false){
            st[q.front()]=false;
            q.pop();
            q.push(x);
            st[x]=true;
        }else if (q.size()<m && st[x]==false){
            q.push(x);
            st[x]=true;
        }else{
            continue;
        }
    }
    cout<<count;
    return 0;
}
//queue实现滑动窗口+哈希表