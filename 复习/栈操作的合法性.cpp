#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int top=-1;
        int flag =1;
        string s;
        cin>>s;
        for(int j=0;j<s.size() && flag;j++)
        {
            if(s.at(j)=='S') top++;
            else top--;
            if(top>=m || top<-1) flag =0;
        }
        if(top!=-1) flag =0;
        if(flag==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}