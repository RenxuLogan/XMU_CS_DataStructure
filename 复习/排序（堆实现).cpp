#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int main()
{
    vector <int> v;
    int n;cin>>n;
    for(int i = 0;i<n;i++)
    {
        int tmp;cin>>tmp;
        v.push_back(tmp);
    }
    make_heap(v.begin(),v.end(),greater<int>());
    while(v.size()>1)
    {
        pop_heap(v.begin(),v.end(),greater<int>());
        int ans= v.back();
        v.pop_back();
        cout<<ans<<" ";
    }
    cout<<v.at(0);
    return 0;
}