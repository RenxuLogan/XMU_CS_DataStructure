#include<iostream>
#include<cmath>
using namespace std;
int n,m;

int main(){
    cin>>m>>n;
    int *array=new int[m];
    int head=0;
    int tail=0;
    int count=1;
    cin>>array[tail];
    for(int i=1;i<n;i++){

        int input;
        cin>>input;
        int flag=1;

        if(abs(tail-head)<m){
            int i=head;
            while(i!=(tail+1)%m){
                if(array[i]==input){
                    flag=0;
                    break;
                }else{
                    i=(i+1)%(m);
                    continue;
                }
            }
        }else{
            int i=head;
            while(i!=(tail+1)%(m)){
                if(array[i]==input){
                    flag=0;
                    break;
                }else{
                    i=(i+1)%(m);
                }
            }
        }
        if(flag==1&&abs(tail-head)<m){
            count++;
        }else if(flag==1&&abs(tail-head)==m){
            count++;
            head=(head+1)%(abs(tail-head));
            tail=(tail+1)%(abs(tail-head));
            array[tail]=input;
        }else if(flag==0){
            continue;
        }


    }
    cout<<count;
    return 0;
}
//核心是队列长度可以直接用m进行替代，abs容易产生问题