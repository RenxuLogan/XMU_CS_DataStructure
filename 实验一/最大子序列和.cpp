#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    int N;
    cin>>n;
    N=n;
    vector<int> v(n);
    while(n--){
        cin>>v[n];
    }   
    int Max_sum=0;
    int sum_now=0;
    for(int i= 0;i<N;i++){
        sum_now+=v[i];
        if(Max_sum<sum_now){
            Max_sum=sum_now;
        }
        if(sum_now<0){
            sum_now=0;
        }
    }

    cout<<Max_sum;

    return 0;
}