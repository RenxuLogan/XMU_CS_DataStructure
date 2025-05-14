#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    queue <int> A;
    queue <int> B;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp;cin>>tmp;
        if(tmp%2 == 0) B.push(tmp);
        else A.push(tmp);
    }
    vector<int> ans;
    while(A.size()!=0 && B.size()!=0)
    {
        if(A.size()==1) 
        {
            int a=A.front();
            A.pop();
            ans.push_back(a);
        }
        else
        {
            int a=A.front();
            A.pop();
            int b=A.front();
            A.pop();
            int c=B.front();
            B.pop();
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(c);
        }
    }
    while(A.size()!=0)
    {
        int a=A.front();
        A.pop();
        ans.push_back(a);
    }
    while(B.size()!=0)
    {
        int a=B.front();
        B.pop();
        ans.push_back(a);
    }
    for(int i=0;i<ans.size();i++)
    {
        if(i==ans.size()-1) cout<<ans.at(i);
        else cout<<ans.at(i)<<" ";
    }
    return 0;
}