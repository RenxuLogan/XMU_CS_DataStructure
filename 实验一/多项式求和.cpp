#include<iostream>
#include<iomanip>
using namespace std;
int times;
int main(){
    double x;
    double ans=0.000;
    cin>>times>>x;
    times++;
    double *array=(double*)malloc( (times) * sizeof(double));
    int n=times;
    while(times--){
        cin>>array[times];
    }
    while(n>0){
        ans=x* (ans+array[n]) ;
        n--;
    }
    ans+=array[0];
    cout<<fixed<<setprecision(3)<<ans<<endl;
    return 0;
}
//重点是cpp中的浮点数的格式化