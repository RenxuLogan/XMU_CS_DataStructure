#include<iostream>
#include<queue>
#include<vector>
using  namespace std;
vector<int> tree[100100];
int beifen[100100];
int main()
{
    int n;cin>>n;
    int root = -1;
    for(int i=1;i<=n;i++) 
    {
        int tmp;
        cin>>tmp;
        if(tmp == -1)
        {
            root = i;
        }
        else
        {
            tree[tmp].push_back(i);
        }
    }
    queue<int> bfs;
    bfs.push(root);
    beifen[root]=1;
    int max_bifen=1;
    int count =1;
    while(bfs.size()!=0)
    {
        int tmp = bfs.front();
        bfs.pop();
        while(tree[tmp].size()!=0)
        {
            int child=tree[tmp].back();
            tree[tmp].pop_back();
            bfs.push(child);
            beifen[child]=beifen[tmp]+1;
            if(beifen[child]>max_bifen) {
                max_bifen=beifen[child];
                count = 0;
            }
            if(beifen[child] == max_bifen){
                count ++;
            } 
        }
    }
    cout<<max_bifen<<endl;
    for(int i=1;i<=n;i++)
    {
        if(beifen[i]==max_bifen &&count-- == 1) cout<<i;
        else if(beifen[i]==max_bifen)cout<<i<<" ";
    }
    return 0;

}