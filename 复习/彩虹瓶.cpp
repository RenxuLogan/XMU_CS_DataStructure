#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    int colour,size,n;
    cin>>colour>>size>>n;
    
    for(int i=0;i<n;i++)
    {
        int count = 1;//当前要装的颜色
        vector <int>stacks;
        int flag =1;

        for(int j=0;j<colour && flag;j++)
        {
            int tmp;
            cin>>tmp;
            if(tmp == count) count ++;
            else if(stacks.size()!=0 && stacks.at(stacks.size()-1) == count  )
            {
                while(stacks.size()!=0 && stacks.at(stacks.size()-1) == count)
                {
                    count ++;
                    stacks.pop_back();
                }
                stacks.push_back(tmp);
            }
            else 
            {
                stacks.push_back(tmp);
            }

            if(stacks.size() == size+1 || stacks.size()>=2 &&  (stacks.at(stacks.size()-1) > stacks.at(stacks.size()-2) ))
            {
                flag =0;
            } 

        }
        while(flag && stacks.size() )
        {
            if(stacks.size()>=2 &&  stacks.at(stacks.size()-1) > stacks.at(stacks.size()-2)) 
            {
                flag= 0;
                break;
            }
            if(stacks.size()!=0 && stacks.at(stacks.size()-1) == count  )
            {
                count ++;
                stacks.pop_back();
            }
        }
        //读栈之前一定要确保栈不为空
        if(flag && count == colour+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
