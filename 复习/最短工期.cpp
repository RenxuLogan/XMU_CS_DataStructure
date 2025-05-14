#include<iostream>
#include<queue>
using namespace std;
int graph[105][105];
int t[105];
int InDegree[105];

void TPSort(int n)
{
    queue<int> q;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(InDegree[i]==0)
        {
            q.push(i);
            t[i]=0;
        }
    }
    int ans=-1;
    while(q.size()!=0)
    {
        int node = q.front();
        q.pop();
        count++;
        for(int i = 0;i<n;i++)
        {
            if(graph[node][i]!=-1 )
            {
                t[i]=max(t[i],t[node]+graph[node][i]);
                ans=max(t[i],ans);
                if(--InDegree[i]==0) q.push(i);
            }
        }
    }
    if(count == n)
    {
        cout<<ans;
    }else cout<<"Impossible";
}

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=-1;
        }
    }
    int m;cin>>m;
    for(int i=0;i<m;i++)
    {
        int start,end,time;
        cin>>start>>end>>time;
        InDegree[end]++;
        graph[start][end]=time;
    }
    TPSort(n);
    return 0;
}