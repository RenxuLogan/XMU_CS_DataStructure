#include<iostream>
using namespace std;
int A[105];
int B[105];
int cmp[105];
int n;

int compare(int a[])
{
    int index=1;
    while(index<=n && a[index] == cmp[index])
    {
        index++;
    }
    if(index==n+1) return 1;
    else return 0;
}

void HeapAdjust(int k,int len)
{
    A[0]=A[k];
    for(int i=k*2;i<=len;i*=2)
    {
        if(i<len && A[i] < A[i+1] ) i++;
        if(A[0]<A[i])
        {
            A[k] = A[i];
            k=i;
        }
        else
        {
            break;
        }
    }
    A[k]=A[0];

}

int HeapSort()
{
    int flag = 0; 
    for(int i= n;i>=1;i--)HeapAdjust(i,n);
    int i=n;
    for(;i>1;i--)
    {
        swap(A[i],A[1]);
        if(compare(A)== 1)
        {
            flag = 1;
            break;
        }
        HeapAdjust(1,i-1);
        if(compare(A) == 1)
        { 
            flag = 1;
            break;
        }
    }
    if(flag == 1 )
    {
        cout<<"Heap Sort"<<endl;
        i--;
        swap(A[i],A[1]);
        HeapAdjust(1,i-1);
        for(int j=1;j<=n;j++)
        {
            if(j == n) cout<<A[j];
            else cout<<A[j]<<" ";
        }
    }
    return flag;
}

void InsertSort ()
{
    int i = 2;
    int flag_equal = 0;
    for(;i<=n;i++)
    {
        B[0] = B[i];
        int idx = i-1;
        while(idx>=1 && B[0]<B[idx])
        {
            B[idx+1]=B[idx];
            idx--;
        }
        B[idx+1]=B[0];
        if(flag_equal == 1)
        {
            break;
        }
        if(compare(B)==1 && flag_equal == 0)
        {
            flag_equal =1;
        }
    }
    cout<<"Insertion Sort"<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i==n) cout<<B[i];
        else cout<<B[i]<<" ";
    }
    return ;
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>A[i];
        B[i]=A[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>cmp[i];
    } 
    if(HeapSort() == 0)
    {
        InsertSort();
    }
    return 0;

}