#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef struct node
{
    int x;int y;int data;
}node;
bool cmp(const node &p1, const node &p2) {
    if (p1.x != p2.x) 
        return p1.x < p2.x; // 按 x 升序
    return p1.y < p2.y;     // 按 y 升序
}
vector<node> v;

int main()
{
    int m,n,t;
    cin>>m>>n>>t;
    for(int i = 0 ; i<t;i++)
    {
        int x,y,value;
        cin>>x>>y>>value;
        v.push_back({y,x,value});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<t;i++)
    {
        cout<<v.at(i).x<<" "<<v.at(i).y<<" "<<v.at(i).data<<endl;
    }
    return 0;
}