#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
unordered_map<string,string> Hashmap;

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        char command;
        string account,password;
        cin>>command >>account>>password;
        if(command=='L')
        {
            if(Hashmap.count(account))
            {
                if(Hashmap[account]!=password) cout << "ERROR: Wrong PW" << endl;
                else cout << "Login: OK" << endl;
            }
            else
            {
                cout<<"ERROR: Not Exist"<<endl;
            }
        }
        else 
        {
            if(Hashmap.count(account))  cout << "ERROR: Exist" << endl;
            else
            {
                Hashmap[account]=password;
                cout << "New: OK" << endl;
            }
        }
    }
    return 0;
}