#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[51]={0};
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        A[tmp]++;
    }
    for(int i=0;i<=50;i++)
    {
        if(A[i]!=0)
        {
            cout<<i<<":"<<A[i]<<endl;
        }
    }
    return 0;
}