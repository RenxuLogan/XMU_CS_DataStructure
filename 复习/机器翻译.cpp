#include<iostream>
#include<unordered_map>
#include<deque>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int count=0;
    deque<int> q;
    for(int i=0;i<n;i++)
    {
        int tmp;cin>>tmp;
        if(q.size() == 0)
        {
            q.push_back(tmp);
            count ++;
        }
        else
        {
            int flag=0;
            for(int j=0;j<q.size() && flag ==0;j++)
            {
                if(q.at(j)==tmp) flag =1;
            }
            if(flag == 0 && q.size()==m)
            {
               q.pop_front();
               q.push_back(tmp);
               count ++; 
            }
            else if(flag == 0 && q.size()<m)
            {
                q.push_back(tmp);
                count ++;
            }
        }
    }
    cout<<count;
    return 0;
}