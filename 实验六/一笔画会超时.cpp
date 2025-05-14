#include <iostream>
#include <vector>
using namespace std;
int visited[1001]={0};
int res=-1;
//深搜->寻找最深的路径
void dfs(int array[1001][1001],int start,int n,int count){
    for (int i = 1; i <= n; ++i) {
        if(visited[i]==0 && array[start][i]==1){
            visited[i]=1;
            dfs(array,i,n,count+1);
        }
        res=res>count?res:count;
    }
    return ;
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

    int ans=0;
    for(int i=1;i<=n;i++){
        res=-1;
        visited[1001]={0};
        visited[i]=1;
        dfs(array,i,n,1);
        ans=ans>res?ans:res;
    }

    if(ans==n){
        cout<<"Y";
    }else{
        cout<<"N";
    }
    return 0;
}
