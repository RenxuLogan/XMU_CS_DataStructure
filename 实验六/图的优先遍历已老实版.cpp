#include<iostream>
using namespace std;
void dfs(int array[][20000],int visited[],int i,int n){
    visited[i]=1;
    cout<<i<<" ";
    for(int j=0;j<n;j++){
        if(array[i][j]== 1 &&visited[j]==0){
            dfs(array,visited,j,n);
        }
    }
    return;
}
void dfs_picture(int array[][20000],int n){
    int visited[20000]={0};
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(array,visited,i,n);
            cout<<endl;
        }
    }
    return;

}
int main(){
    int n;int e;
    cin>>n>>e;
    int array[20000][20000]={0};
    for(int i=0;i<e;i++){
        int a;int b;
        cin>>a>>b;
        array[a][b]=1;
    }
    dfs_picture(array,n);
    return 0;
}