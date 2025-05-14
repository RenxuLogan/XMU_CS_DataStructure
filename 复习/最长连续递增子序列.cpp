#include<iostream>
#include<cstring>
using namespace std;
int num  [100005];
int list [100005];
int main()
{
    memset(list,0,sizeof(list));
    int n;cin>>n;
        cin>>num[0];
        list[0] = 1;
        int max=1;
        int max_index =0;
        for(int i = 1 ;i<n;i++)
        {
            cin>>num[i];
            if(num[i]>num[i-1]) list[i]=list[i-1]+1;
            else list[i]=1;
            if(list[i] > max)
            {
                max=list[i];
                max_index = i;
            }
        }
        for(int i =max_index-max+1;i<max_index;i++)
        {
            cout<<num[i]<<" ";
        }
        cout<<num[max_index];
    return 0;
}