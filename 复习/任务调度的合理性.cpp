#include<iostream>
#include<queue>
using namespace std;
int graph[105][105];
int InDegree [105]={0};
int TPSort(int n)
{
    queue <int> q;
    int leaving =n;
    for(int i=1;i<=n;i++)
    {
        if(InDegree[i]==0)
        {
            q.push(i);
        }
    }
    while (q.size()!=0)
    {
        int node = q.front();
        q.pop();
        leaving --;
        for(int i=1;i<=n;i++) {
            if(graph[node][i]==1 && --InDegree[i]==0) //只有在这个时候才能入队，也就是说在当前节点的邻接节点为0的时候才能进行入队！！  
            {
                q.push(i);
            }   
        }

    }
    if(leaving==0) return 1;
    else return 0;
}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        for(int j=0;j<k;j++)
        {
            int input;cin>>input;
            graph[input][i]=1;
            InDegree[i]++;
        }
    }
    if(TPSort(n)) cout<< 1;
    else cout<< 0;
    return 0;
}