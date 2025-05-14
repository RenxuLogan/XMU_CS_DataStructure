#include<iostream>
#include<stack>
#include<string>
#include<climits>
using namespace std;
int cal(int a,int b,string sign){
    if(sign=="+"){
        return a+b;
    }else if(sign=="*"){
        return a*b;
    }else if(sign=="-"){
        return b-a;
    }else{
        if(a==0){
            return INT_MAX;
        }else{
            return b/a;
        }
    }
}

int main (){
    stack <string> stacks;
    int flag=0;
    string error;
    while(true){
        string x;
        cin>>x;//依次读取表达式

        if (x == "+" || x == "*" || x == "/" || x == "-") { 
            if(stacks.size()<2){
                flag=1;
                break;
            }else{
                int a = stoi(stacks.top());
                stacks.pop();
                int b = stoi(stacks.top());
                stacks.pop();
                int result = cal(a,b,x);
                if(result==INT_MAX){
                    flag =2;
                    error="Error: "+to_string(b)+"/"+to_string(a);
                    break;
                }
                stacks.push(to_string(result));
            }
        } else if (x != "#") {
            stacks.push(x); 
        } else {
            break;
        }
    }
    if(stacks.size()>1 || flag==1){
      cout<< "Expression Error: " <<stacks.top()<<endl;
    }else if(flag==0){
        cout<<stacks.top()<<endl;
    }else{
        cout<< error <<endl;
    }
    return 0;
}