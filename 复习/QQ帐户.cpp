#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,string> map;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        char sit ;cin>>sit;
        string account;
        string passowrd;
        cin>>account>>passowrd;
        if(sit == 'L')
        {
            if(map.count(account) <= 0)
            {
                cout<<"ERROR: Not Exist"<<endl;
            }
            else if(map[account]==passowrd)
            {
                cout<<"Login: OK"<<endl;
            }
            else
            {
                cout<<"ERROR: Wrong PW"<<endl;
            }
        }
        if(sit == 'N')
        {
            if(map.count(account)<=0)
            {
                cout<<"New: OK"<<endl;
                map[account]=passowrd;
            }
            else{
                cout<<"ERROR: Exist"<<endl;
            }
        }
    }
    return 0;
}