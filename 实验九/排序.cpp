#include<iostream>
#include<cstdio>
using namespace std;

int move(int A[],int low,int high)
{
    A[0]=A[low];
    while(high != low)
    {
        while(high > low && A[high] > A[0]) high--;
        A[low] = A[high];
        while(high > low && A[0]< A[low]) low++;
        A[high]=A[low];
    }
    A[low]=A[0];
    return low;
}

int median_of_three(int A[], int low, int high) {
    int mid = (low + high) / 2;
    if (A[low] > A[high]) swap(A[low], A[high]);
    if (A[low] > A[mid]) swap(A[low], A[mid]);
    if (A[mid] > A[high]) swap(A[mid], A[high]);
    return mid;
}

int mymove(int A[], int low, int high) {
    int pivot = median_of_three(A, low, high);  // 使用三数中值选择基准
    swap(A[low], A[pivot]);  // 将基准元素与数组的第一个元素交换
    A[0] = A[low];
    while (high != low) {
        while (high > low && A[high] > A[0]) high--;
        A[low] = A[high];
        while (high > low && A[0] < A[low]) low++;
        A[high] = A[low];
    }
    A[low] = A[0];
    return low;
}


void QuickSort(int A[],int low,int high)
{
    if(low<high)
    {
        int q=mymove(A,low,high);
        QuickSort(A,low,q-1);
        QuickSort(A,q+1,high);
    }
}



int main()
{
    int n;
    cin>>n;
    int *A=(int *)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++) cin>>A[i];
    QuickSort(A,1,n);
    for(int i=1;i<=n-1;i++) cout<<A[i]<<" ";
    cout<<A[n];
    return 0;
}