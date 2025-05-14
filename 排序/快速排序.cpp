#include<iostream>
using namespace std;

int mymove(int A[],int low,int high)
{
    A[0]=A[low];
    while(high!=low)
    {
        while(high>low && A[high]>A[0]) high--;
        A[low]=A[high];
        while(high>low && A[low]<A[0]) low++;
        A[high]=A[low];
    }
    A[low]=A[0];
    return low;
}
void  QuickSort(int A[],int low,int high)
{
    if(low>=high) return ;
    int p=mymove(A,low,high);
    for(int i =1;i<=8 ;i++) cout<<A[i]<<" ";
    cout<<endl;
    QuickSort(A,low,p-1);
    QuickSort(A,p+1,high);
}



int main()
{
    int A[]={0,29,18,25,47,58,12,51,10};
    QuickSort(A,1,9);
    for(int i=1;i<=8;i++) cout<<A[i]<<" ";
    return 0;
}