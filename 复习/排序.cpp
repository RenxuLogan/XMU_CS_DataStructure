#include<iostream>
using namespace std;
int cmp(const void* a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int a[100010];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    qsort(a,n,sizeof(int),cmp);
    for(int i=0;i<n-1;i++)cout<<a[i]<<" ";
    cout<<a[n-1];
    return 0;
}