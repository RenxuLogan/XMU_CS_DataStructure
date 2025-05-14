#include<iostream>
#include<deque>
using namespace std;
typedef struct Node
{
    int x;int y;
    int data;
}Node;

deque <Node> v1;
deque <Node> v2;
deque <Node> ans;

int main()
{
    int row,col;
    cin>>row>>col;
    int num_a;
    cin>>num_a;
    for(int i=0;i<num_a;i++)
    {
        int x,y,value;
        cin>>x>>y>>value;
        v1.push_back({x,y,value});
    }

    int num_b;
    cin>>num_b;

    for(int i=0;i<num_b;i++)
    {
        int x,y,value;
        cin>>x>>y>>value;
        v2.push_back({x,y,value});
    }
    
    while(v1.size()!=0 && v2.size()!=0)
    {
        Node tmp1 = v1.front();
        Node tmp2 = v2.front();
        if(tmp1.x<tmp2.x)
        {
            ans.push_back(tmp1);
            v1.pop_front();
        }
        else if (tmp1.x>tmp2.x)
        {
            ans.push_back(tmp2);
            v2.pop_front();            
        }
        else
        {
            if(tmp1.y<tmp2.y)
            {
                ans.push_back(tmp1);
                v1.pop_front();
            }
            else if (tmp1.y>tmp2.y)
            {
                ans.push_back(tmp2);
                v2.pop_front();            
            }
            else
            {
                if(tmp1.data+tmp2.data!=0) ans.push_back({tmp1.x,tmp2.y,tmp1.data+tmp2.data});
                v2.pop_front();   
                v1.pop_front();               
            }

        }
    }
    while(v1.size())
    {
        ans.push_back(v1.front());
        v1.pop_front();
    }
    while(v1.size())
    {
        ans.push_back(v2.front());
        v2.pop_front();
    }
    cout<<ans.size()<<endl;
    for (const auto& node : ans) {
        cout << node.x << " " << node.y << " " << node.data << endl;
    }
    return 0;
}