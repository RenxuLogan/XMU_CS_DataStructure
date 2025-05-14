//拓扑排序
#include <iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 105

int n;
int graph[MAX_SIZE][MAX_SIZE];
int indegree[MAX_SIZE];

int TopologicalSort()
{
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0) v.push_back(i);
    }

    int count=0;
    while(!v.empty())
    {
        int current_node=v.back();
        v.pop_back();
        count++;
        for(int j=1;j<=n;j++)
        {
            if(graph[current_node][j] &&(--indegree[j])==0)
            {
                v.push_back(j);
            }
        }
    }
    if(count == n) return 1;
    else return 0; 
    

}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        for(int j=0;j<k;j++)
        {
            int node;
            cin>>node;
            graph[i][node]=1;
            indegree[node]++;
        }
    }
    cout<<TopologicalSort();
    return 0;
}