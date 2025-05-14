#include<iostream>
#include<cstring>
#define MAXN 1000010
using namespace std;

int kmp_next[MAXN], la, lb; // kmp数组存储前缀表，la和lb分别为a和b的长度，j为匹配的索引
char a[MAXN], b[MAXN];


int main() {
    cin >> a+1 >> b+1;
    la = strlen(a+1);  
    lb = strlen(b+1);  
    int i=2,j=0;
    kmp_next[i]=0;
    kmp_next[0]=0;
    kmp_next[1]=0;
    while(i<=lb){
        if(j==0||b[i]==b[j]){
            i++;
            j++;
            kmp_next[i]=j;
        }else{
            j=kmp_next[j];
        }
    }
    j=1;
    i=1;
    while(i<=la){
        if(j==0||a[i]==b[j]){
            i++;
            j++;
        }else{
            j=kmp_next[j];
        }
        if(j>lb){
            cout << i-lb << endl;
            j=kmp_next[j];
        }
    }
    // 输出前缀数组kmp
    for (int i = 1; i < lb; i++) cout << kmp_next[i] << " ";
    cout << kmp_next[lb] << endl;
    return 0;
}
