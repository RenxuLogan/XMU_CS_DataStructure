#include<iostream>
using namespace std;
void Merge(int A[],int low,int mid,int high,int n)
{
    int *B=(int *)malloc((n+1)*sizeof(int));
    for(int i=low;i<=high;i++) B[i]=A[i];
    int i,j,k;//k是A中的索引
    for(i=low,j=mid+1,k=low;i<=mid&&j<=high;k++)
    {                           //这里一定要用if-else不能用两个if 因为第一个if会影响第二个的操作
        if(B[i]>B[j]) 
        {
            A[k]=B[i++];
        }
        else
        {
            A[k]=B[j++];
        }
    }
    while(i<=mid) A[k++]=B[i++];
    while(j<=high) A[k++]=B[j++];
}
//基础的合并操作实现

//非递归实现需要手动遍历分组大小
void MergeSort(int A[],int n)
{
    for(int sub =1 ;sub <= n;sub*=2)
    {
        for(int i=1;i<=n;i+=(2*sub))
        {
            int low=i,mid=i+sub-1,high=low+2*sub-1;
            if(low  >= n) break;
            if(high >=n)  high=n-1;
            Merge(A,low,mid,high,n);
        }
    }
}


int main ()
{
    int A[]={0,7,3,1,2,4,68,6,45,34,24,654,14};
    MergeSort(A,12);
    for(int i=1;i<=12;i++) cout<<A[i]<<" ";
    return 0;
}