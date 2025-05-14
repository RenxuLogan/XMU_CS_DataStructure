#include<iostream>

using namespace std;
int A[105];
int B[105];
int target[105];
int cmpA(int n)
{
    int i=1;
    while(i<=n && A[i]==target[i])i++;
    if(i==n+1 )return 1;
    else return 0;
}
int cmpB(int n)
{
    int i=1;
    while(i<=n && B[i]==target[i])i++;
    if(i==n+1 )return 1;
    else return 0;
}
void HeapAdjust(int k,int n)
{
    A[0]=A[k];
    for(int i=k*2;i<=n;i*=2)
    {
        if(i<n && A[i]<A[i+1]) i++;
        if(A[k]>A[i]) break;
        if(A[k]<A[i]) swap(A[k],A[i]);
        k=i;
    }
    A[k]=A[0];
}

int HeapSort(int n)
{
    int flag = 0;
    for(int i=n/2;i>0;i--) HeapAdjust(i,n);
    int i;
    for(i= n;i>=1;i--)
    {
        swap(A[i],A[1]);
        if(cmpA(n)){
            flag =1;
            break;
        } 
        HeapAdjust(1,i-1);
        if(cmpA(n)){
            flag =1;
            break;
        } 
    }

    if(flag==1)
    {
        i--;
        cout<<"Heap Sort"<<endl;
        swap(A[i],A[1]);
        HeapAdjust(1,i-1);
        for(int i=1;i<=n-1;i++) cout<<A[i]<<" ";
        cout<<A[n];
    }

    return flag;
}

int InsertSort(int n)
{
    int flag=0;int i;
    for(i=2;i<=n;i++)//日你妈竟然是从第二个开始的
    {
        B[0]=B[i];
        if(cmpB(n)==1) 
        {
            flag=1;
            break;
        }
        int j=i-1;
        while(B[0] < B[j]) {
            B[j+1]=B[j];
            j--;
        }
        B[j+1]=B[0];
        if(cmpB(n)==1) 
        {
            flag=1;
            break;
        }

    }

    if(flag==1)
    {
        cout<<"Insertion Sort"<<endl;
        i++;
        B[0]=B[i];
        int j=i-1;
        while(B[0] < B[j]) {
            B[j+1]=B[j];
            j--;
        }
        B[j+1]=B[0];
        for(int i=1;i<=n-1;i++) cout<<B[i]<<" ";
        cout<<B[n];
    }
    return flag;
}


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>A[i];
        B[i]=A[i];
    }
    for(int i=1;i<=n;i++) cin>>target[i];
    if(HeapSort(n)!=1)
    {
        InsertSort(n);
    }
    return 0;


}