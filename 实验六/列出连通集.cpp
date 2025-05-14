#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
void bfs(int array[10][10],int visited[10],int start,int n){
    queue<int> q;
    q.push(start);
    visited[start]=1;
    cout<<"{ ";
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(int i=0;i<n;i++){
            if(array[temp][i]==1&&visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
    cout<<"}"<<endl;
}
void bfs_picture(int array[10][10],int n){
    int visited[10]={0};
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            bfs(array,visited,i,n);
        }
    }
}

void dfs(int array[10][10],int visited[10],int start,int n){
    visited[start]=1;
    cout<<start<<" ";
    for(int i=0;i<n;i++){
        if(array[start][i]==1&&visited[i]==0){
            dfs(array,visited,i,n);
        }
    }
}
void dfs_picture(int array[10][10],int n){
    int visited[10]={0};
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            cout<<"{ ";
            dfs(array,visited,i,n);
            cout<<"}"<<endl;
        }
    }

}

int main(){
    int array[10][10]={0};
    int n;int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a;int b;
        cin>>a>>b;
        array[a][b]=1;
        array[b][a]=1;
    }
    dfs_picture(array,n);
    bfs_picture(array,n);
    return 0;


}