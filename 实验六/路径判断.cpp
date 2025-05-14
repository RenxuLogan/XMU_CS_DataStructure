#include <iostream>
#include <stdio.h>
#include<cstring>
using namespace std;
int is_find=0;
int visited[10]={0};
void dfs(int array[][10],int start,int target,int n){
    if(start==target){
        is_find=1;
        return;
    }
    visited[start]=1;
    for(int i=0;i<n;i++){
        if(array[start][i]==1&&visited[i]==0){
            dfs(array,i,target,n);
        }
    }
}

int main(){
    int n;int e;
    cin>>n>>e;
    int array[10][10];
    memset(array, 0, sizeof(array));
    for(int i=0;i<e;i++){
        int a;int b;
        cin>>a>>b;
        array[a][b]=1;
        array[b][a]=1;
    }
    int start;int target;
    cin>>start>>target;
    dfs(array,start,target,n);
    if(is_find==1){
        printf("There is a path between %d and %d.",start,target);
    }else{
        printf("There is no path between %d and %d.",start,target);
    }
    return 0;
}