#include<iostream>
using namespace std;
int stacks[10005];
int main()
{
    int colour,size,k;
    cin>>colour>>size>>k;
    for(int i=0;i<k;i++)
    {
        int top = -1;
        int current =1;
        int flag=1;
        int j = 0;
        for(;j<colour && flag == 1;j++)
        {
            int tmp;cin>>tmp;
            if(tmp == current)
            {
                current ++;
            }
            else
            {
                while (top!=-1 && stacks[top] == current)
                {
                    current ++;
                    top--;
                }
                stacks[++top]=tmp;
            }
            if(top >= size) flag =0;
            if(top>0 && tmp >stacks[top-1])  flag =0;
        }
        for(;j<colour;j++)
        {
            int tmp;cin>>tmp;
        } 
        while(top !=-1 && flag==1)
        {
            if(stacks[top]==current)
            {
                current++;
                top--;
            }
            else 
            {
                flag=0;
                break;
            }
        }
        if(flag== 1 && current==colour+1 && top==-1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}