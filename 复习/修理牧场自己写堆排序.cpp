#include<iostream>
using namespace std;

int heap[10005];

void HeapAdjust(int k,int n)
{
    heap[0]=heap[k];
    for(int i=k*2;i<=n;i++)
    {
        if(i<n && heap[i] > heap[i+1]) i++;
        if(heap[0] > heap[i])
        {
            heap[k]=heap[i];
            k=i;
        }
        else break;
    }
    heap[k]=heap[0];
}
void HeapSort(int n)
{
    for(int i = n/2;i>=1;i--) HeapAdjust(i,n);
}

void HeapInsert(int value,int n)
{
    heap[n+1]=value;
    HeapSort( 1 + n );
}

int HeapPop(int n)
{
    int ans;
    if(n<1) return -1;
    else 
    {
        ans = heap[1];
        heap[1] = heap[n];
        HeapAdjust(1,n-1);
    }
    return ans;
}


int main()
{
    int n;cin>>n;
    int count = 0;
    for(int i=1;i<=n;i++) cin>>heap[i];
    HeapSort(n);
    while(n!=1)
    {
        int a=HeapPop(n--);
        int b=HeapPop(n--);
        int tmp =a+b;
        count += tmp;
        HeapInsert(tmp,n++);
    }
    cout <<count;
    return 0;

}