#include<iostream>
using namespace std;
int a[1000100];

int main()
{
    int n;int target;
    cin>>n>>target;

    for(int i=1;i<=n;i++) cin>>a[i];

    int start =1;int end = n;
    int mid =(start + end)/2;
    while(start <= end)
    {
        mid=(start + end)/2;
        if(a[mid]>target || a[mid]==target)
        {
            end=mid-1;
        }
        else
        {
            start = mid +1;
        }
    }
    if(start<=n)cout<< start;
    else cout<<(n+1);
    return 0;
}