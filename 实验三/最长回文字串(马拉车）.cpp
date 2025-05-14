#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string init(string s) {
    string res;
    res += '@';  // 在开头加入哨兵防止越界
    for(int i = 0; i < s.size(); ++i) {
        res += '#';
        res += s[i];
    }
    res += '#';
    res += '$';  // 结尾同样加入哨兵防止越界
    return res;
}

int manacher(string s){
    int ans=-1;
    int mx=0;
    int id=0;
    int len[s.length()];
    memset(len,0,sizeof(len));
    for(int i=1;i<s.length()-1;i++){
        if(mx>i){
            len[i]=min(mx-i,len[2*id-i]);
        }else{
            len[i]=1;
        }
        while(s[i-len[i]] == s[i+len[i]]){
            len[i]++;
        }
        if(i+len[i]>mx){
            mx=i+len[i];
            id=i;
        }
        ans=max(len[i],ans);
    }

    return (ans-1);

}
int main(){
    string s;
    getline(cin,s);
    string str=init(s);
    cout<<manacher(str)<<endl;
    return 0;
}