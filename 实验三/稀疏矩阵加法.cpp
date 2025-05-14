#include<iostream>
#include<vector>
#include <utility> 
#include <cstring>
#include<map>
using namespace std;
int main(){
    int row,col;
    cin>>row>>col;
    map<pair<int,int>,int>A,B;
    int n1,n2;
    cin>>n1;
    for (int k=0;k<n1;k++){
        int i,j,num;
        cin>>i>>j>>num;
        A[{i,j}]=num;
    } 
    cin>>n2;
    for(int k=0;k<n2;k++){
        int i,j,num;
        cin>>i>>j>>num;
        B[{i,j}]=num;
    }
    for (auto& entry : B) {
        A[entry.first] += entry.second;
    }
    int count = 0;
    for (const auto& entry : A) {
        if (entry.second != 0) {  // 只统计非零元素
            count++;
        }
    }
    cout<<count<<endl;
    for (const auto& entry : A) {
        if (entry.second != 0) {
            cout << entry.first.first << " " << entry.first.second << " " << entry.second << endl;
        }
    }

    return 0;
}