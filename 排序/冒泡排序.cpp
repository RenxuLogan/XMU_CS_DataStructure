#include<iostream>
using namespace std;

void BubbleSort(int A[],int n)
{
    int i=n;
    while(i>1)
    {
        int LastChangeInde=1;
        for(int j=1;j<i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                LastChangeInde=j;
            }
        }
        i=LastChangeInde;
    }
}


int main()
{
    int A[]={0,7,3,1,2,4,68,6,45,34,24,654,14};
    BubbleSort(A,12);
    for(int i=1;i<=12;i++) cout<<A[i]<<" ";
    return 0;
}