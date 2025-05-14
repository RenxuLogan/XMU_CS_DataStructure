#include<iostream>
using namespace std;
int Tree[1005];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>Tree[i];
    int i,j;
    cin>>i>>j;
    if(Tree[i]==0)
    {
        cout<<"ERROR: T["<<i<<"] is NULL";
        exit(EXIT_SUCCESS);
    }
    else if(Tree[j]==0)
    {
        cout<<"ERROR: T["<<j<<"] is NULL";
        exit(EXIT_SUCCESS);
    }
    else
    {
        while(i!=j)
        {
            if(i>j) i/=2;
            else j/=2;
            if(Tree[i]==0)
            {
                cout<<"ERROR: T["<<i<<"] is NULL";
                exit(EXIT_SUCCESS);
            }
            else if(Tree[j]==0)
            {
                cout<<"ERROR: T["<<j<<"] is NULL";
                exit(EXIT_SUCCESS);
            }            
        }
    }
    cout<<i<<" "<<Tree[i];
    return 0;
    
}