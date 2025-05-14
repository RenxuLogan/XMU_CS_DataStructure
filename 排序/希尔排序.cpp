#include<iostream>
using namespace std;
void ShellSort(int A[],int n)
{
    int d=n/2;
    for(;d>=1;d/=2)
    {
        for(int i=d+1;i<=n;i++)
        {
            if(A[i]<A[i-d])
            {
                A[0]=A[i];
                int j = i - d ;
                for(;j>0&&A[j]>A[0];j-=d) A[j+d] = A[j];
                A[j+d]=A[0];
            }
        }
    }
    return ;
}


int main ()
{
    int A[]={0,7,3,1,2,4,68,6,45,34,24,654,14};
    ShellSort(A,12);
    for(int i=1;i<=12;i++) cout<<A[i]<<" ";
    return 0;
}

//增量是多少就会分多少组