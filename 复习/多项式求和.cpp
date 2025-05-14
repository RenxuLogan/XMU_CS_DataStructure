#include<iostream>
using namespace std;
float num[30005];
int main()
{
    int n;float x;
    cin>>n>>x;
    for(int i = 0;i<=n;i++)
    {
        cin>>num[i];
    }
    float ans = 0;
    for(int i=0;i<=n;i++)
    {
        ans= ans*x + num[i];
    }
    printf("%.3f",ans);
    return 0;
}