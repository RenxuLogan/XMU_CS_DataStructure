#include<iostream>
#include<string>
//就是利用中心拓展法将包含中心和不包含中心（偶数长度和技术长度的字串都遍历一遍）
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int ans=-1;
    for(int i=0;i<s.length();i++){
        int j=1;
        int len=1;
        while(i-j>=0&&i+j<s.length()&&s[i-j]==s[i+j]){
            len+=2;
            j++;
        }
        ans=max(ans,len);
        len=0;
        j=0;
        while(i-j>=0&&i+j<s.length()&&s[i-j-1]==s[i+j]){
            len+=2;
            j++;
        }
        ans=max(ans,len);
    }
    cout<<ans;
    return 0;
}