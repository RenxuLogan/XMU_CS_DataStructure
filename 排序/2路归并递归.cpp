#include<iostream>
using namespace std;
void Merge(int A[],int low,int mid,int high,int n)
{
    int *B=(int *) malloc((n+1)*sizeof(int));
    for(int i=low;i<=high;i++) B[i]=A[i];
    int i,j,k;
    for(i=low,j=mid+1,k=low;i<=mid && j<=high;k++) //这里的k应当初始化为low，
                                                    //因为B和A是对应的，我们修改的是A[low,high]这段区间，所以K的变化区间是[low,high]
    {
        if(B[i]>B[j]) A[k] = B[i++];
        else A[k]=B[j++];
    }
    while(i<=mid) A[k++] = B[i++];
    while(j<=high)A[k++] = B[j++]; //md这里已经不是循环内部了所以要对k的所以就行递增！！！

} 

void MergeSort(int A[],int low,int high,int n)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(A,low,mid,n);
        MergeSort(A,mid+1,high,n);
        Merge(A,low,mid,high,n);
    }
}


int main()
{
    int A[]={0,7,3,1,2,4,68,6,45,34,24,654,14};
    MergeSort(A,1,12,12);
    for(int i=1;i<=12;i++) cout<<A[i]<<" ";
    return 0; 
}