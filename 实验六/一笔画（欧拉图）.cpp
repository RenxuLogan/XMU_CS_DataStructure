#include<iostream>
#include<queue>
using namespace std;
int bfs(int array[][1001],int n){
    int visit[1001]={0};
    visit[1]=1;
    queue<int> q;
    q.push(1);
    int count=1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(array[temp][i]==1 && visit[i]==0){
                visit[i]=1;
                q.push(i);
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n;int m;
    cin>>n>>m;
    int array[1001][1001]={0};
    for(int i=0;i<m;i++){
        int a;int b;
        cin>>a>>b;
        array[a][b]=1;
        array[b][a]=1;
    }

    
    int sum=0;
    for(int i=1;i<=n && sum<=2;i++){
        int count=0;
        for(int j=1;j<=n;j++){
            if(array[i][j]==1){
                count++;
            }
        }
        if(count%2==1){
            sum++;
        }
    }
    if(bfs(array,n)== n  && sum<=2){
        cout<<"Y";
    }else{
        cout<<"N";
    }
    return 0;
}