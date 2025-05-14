#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

int main()
{
    int N, P;
    int Hash[1001];
    memset(Hash,-1,sizeof(Hash));
    cin>>N>>P;
    for(int i=0;i<N;i++)
    {
        char tmp[10];
        cin >> tmp;
        int n=strlen(tmp);
        int ans=0;
        for(int i=n-3;i<=n-1;i++)
        {
            ans=tmp[i]-'A'+ans*32;
        }
        ans=ans % P;
        int d=1;
        int count = 1;
        int p = ans;
        while(Hash[p] != -1)
        {
            p=ans+d;
            if(d<0)
            {
                count ++;
                d= count ^2;
            }else d=-d;
            if(p>=P || p<0) p=ans;
        }
        Hash[p]=1;
        cout << p  ;
        if(i==N-1) continue;
        else cout<<" ";
        
    }
    return 0;
}