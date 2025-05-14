#include<iostream>
using namespace std;

void SelectSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<=n;j++)
        {
            if(A[j]<A[min]) min=j;
        }
        if(min!=i) swap(A[i],A[min]);
    }
}


int main()
{
    int A[]={0,7,3,1,2,4,68,6,45,34,24,654,14};
    SelectSort(A,12);
    for(int i=1;i<=12;i++) cout<<A[i]<<" ";
    return 0;
}