#include<iostream>
using namespace std;

int InOrder[35];
int LastOrder[35];
int PreOrder[35];
int Pindex=0;

void Generate(int start ,int end,int index_in_LastOrder)
{
    if(start>end ) return ;
    int index_in_InOrder=start;
    for(;index_in_InOrder<=end;index_in_InOrder++)
    {
        if(LastOrder[index_in_LastOrder]==InOrder[index_in_InOrder]) break;
    }
    PreOrder[Pindex++] = LastOrder[index_in_LastOrder];
    Generate(start, index_in_InOrder-1, index_in_LastOrder-(end-index_in_InOrder)-1);
    Generate(index_in_InOrder+1, end , index_in_LastOrder-1);
    
}

int main()
{
    Pindex=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>LastOrder[i];
    for(int i=0;i<n;i++) cin>>InOrder[i];
    Generate(0 ,n-1,n-1);
    cout<<"Preorder: ";
    for(int i=0;i<n;i++)
    {
        if(i==n-1)cout<<PreOrder[i];
        else cout<<PreOrder[i]<<" ";
    }
    return 0;
}