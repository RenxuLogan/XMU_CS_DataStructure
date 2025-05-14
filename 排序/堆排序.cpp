#include<iostream>

using namespace std;
void HeapAdjust(int A[],int k,int n)
{
    A[0]=A[k];
    for(int i=2*k;i<=n;i*=2)
    {
        if(i<n && A[i+1]>A[i]) i++;
        if(A[0]>A[i]) break;
        else
        {
            A[k]=A[i];
            k=i;
        }
    }
    A[k]=A[0];
}
void HeapSort (int A[],int n)
{
    for(int i=n/2;i>0;i--) HeapAdjust(A,i,n);
    for(int i=n;i>1;i--)
    {
        swap(A[i],A[1]);
        HeapAdjust(A,1,i-1);
    }
    return ;
}
int main()
{
    int A[]={0,7,3,1,2,4,68,6,45,34,24,654,14};
    HeapSort(A,12);
    for(int i=1;i<=12;i++) cout<<A[i]<<" ";
    return 0;

}