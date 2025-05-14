#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
int main()
{
    int n;cin>>n;
    int count =0;
    vector<int>v;
    for(int i=0;i<n;i++) 
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    make_heap(v.begin(),v.end(),greater<int>());
    while(v.size()>1)
    {
        pop_heap(v.begin(),v.end(),greater<int>());
        int a= v.back();
        v.pop_back();
        pop_heap(v.begin(),v.end(),greater<int>());
        int b= v.back();
        v.pop_back();        
        int tmp = a+b ;
        v.push_back(tmp);
        make_heap(v.begin(),v.end(),greater<int>());        
        count +=tmp;
    }
    cout<<count ;
    
}