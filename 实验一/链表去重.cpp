#include<iostream>
#include<iomanip>
using namespace std;
const int N = 100010;
const int M = 10010;
bool a[M]={false};
int d[N];
int i[N];
void print_node(int head){
    int p=head;
    while(p!=-1){
        cout<<setfill('0') <<setw(5)<<p<<" "<<d[p]<<" ";
        if(i[p]==-1){
            cout<<"-1"<<endl;
        }else{
            cout<<setfill('0')<<setw(5)<<i[p]<<endl;
        }
        p=i[p];
    }
}
int main(){
    int head1,n;
    cin>>head1>>n;
    while(n--){
        int address,num,next;
        cin>>address>>num>>next;
        d[address]=num;
        i[address]=next;
    }
    int now=head1;
    int pre=now;
    int head2=-1;
    int pre2=-1;
    while(now!=-1){
        if(a[abs(d[now])]==false){
            a[abs(d[now])]=true;
            pre=now;
            now=i[now];
        }else{
            if(head2==-1){
                head2=now;
                pre2=now;
                i[pre]=i[now];
                now=i[now];
            }else{
                i[pre]=i[now];
                i[pre2]=now;
                pre2=now;
                now=i[now];
            }
        }
    }
    i[pre]=-1;
    i[pre2]=-1;
    print_node(head1);
    print_node(head2);
    return 0;
}
//对数字的格式化输出和不知一个位置的数字需要被格式化输出
