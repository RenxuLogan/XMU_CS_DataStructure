#include<iostream>
#include<queue>
using namespace std;
int n,ans;

int main(){
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        minHeap.push(x);
    }
    while(!minHeap.empty()){
        int a=minHeap.top();
        minHeap.pop();
        if(!minHeap.empty()){
            ans+=a+minHeap.top();
            minHeap.push(a+minHeap.top());
            minHeap.pop();
        }
    }
    cout<<ans;
    return 0;
}
//为什么不加入最后的一个节点呢？因为他的两个小块以及计算过了（两个合并成一块的时候）再计算会产生重复计算
//用到的知识是最小堆的插入、删除