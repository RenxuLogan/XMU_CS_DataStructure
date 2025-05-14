#include<iostream>
#include<deque>

using namespace std;
int main()
{
    deque<int> q1;
    deque<int> q2;
    deque<int> ans;
    int tmp;cin>>tmp;
    while(tmp!= -1)
    {
        q1.push_back(tmp);
        cin>>tmp;
    }
    cin>>tmp;
    while(tmp!= -1)
    {
        q2.push_back(tmp);
        cin>>tmp;
    }
    while(q1.size()!=0 && q2.size()!=0)
    {
        if(q1.front() == q2.front())
        {
            ans.push_back(q1.front());
            q1.pop_front();
            q2.pop_front();
        }
        while(q2.size() && q1.front() > q2.front())
        {
            q2.pop_front();
        }
        while(q1.size() && q1.front() < q2.front())
        {
            q1.pop_front();
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        if(i==ans.size()-1)cout<<ans.at(i);
        else cout<<ans.at(i)<<" ";
    }
    if(ans.size()==0)
    {
        cout<<"NULL";
    }
    return 0;
}
