#include<iostream>
#include <string>
#include<cstring>
using namespace std;
int stacks[50000];
int top=-1;
string error_massege=" ";
void cul(string input)
{
    if(top==0) {
        error_massege="Expression Error: ";
        error_massege+=to_string(stacks[top]);
        return;
    }
    if(input == "+")
    {
        int a=stacks[top--];
        int b=stacks[top--];
        int tmp =a+b;
        stacks[++top]=tmp;
    }
    else if(input == "-")
    {
        int a=stacks[top--];
        int b=stacks[top--];
        int tmp =b-a;
        stacks[++top]=tmp;
    }
    else if(input == "*")
    {
        int a=stacks[top--];
        int b=stacks[top--];
        int tmp =b*a;
        stacks[++top]=tmp;
    }
    else if( input =="/")
    {
        int a=stacks[top--];
        int b=stacks[top--];
        if(a==0)
        {
            error_massege="Error: ";
            error_massege += to_string(b);
            error_massege+="\\";
            error_massege += "0";
        }
        else 
        {
            stacks[++top]=b/a;
        }
    }
    return;
}


int main()
{
    string input;
    cin>>input;
    while(input != "#" &&  error_massege==" ")
    {

        if (input == "+" || input == "-" ||input == "*" ||input == "/" )
        {
            cul(input);
        }
        else
        {
            stacks[++top]=stoi(input);

        }

        cin>>input;
    }
    if(top!=0 && error_massege ==" ")
    {
        error_massege="Expression Error: ";
        error_massege+= to_string(stacks[top]);
    }
    if(error_massege !=" ") cout<<error_massege;
    else cout<<stacks[top];
    return 0;
}