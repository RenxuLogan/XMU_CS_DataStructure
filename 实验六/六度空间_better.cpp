#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int bfs(int array[][1001],int n,int start){
    queue<int> q;
    int count =0;int sum =0;
    int visit[1001]={0};
    int level[1001]={0};
    q.push(start);
    visit[start]=1;
    level[start]=0;
    while(!q.empty() && count< 6){
        int temp=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(array[temp][i]==1 && visit[i]==0){
                level[i]=level[temp]+1;
                count = count > level[i]? count : level[i];
                visit[i]=1;
                sum++;
                q.push(i);
            }
        }
    }
    return sum+1;

}



int main(){
    int n,m;
    cin>>n>>m;
    int array[1001][1001];
    memset(array,0,sizeof(array));
    for(int i=0;i<m;i++){
        int a;int b;
        cin>>a>>b;
        array[a][b]=1;
        array[b][a]=1;
    }
    
    for(int i=1;i<=n;i++){
        int sum=bfs(array,n,i);
        float ans=(sum*1.0/n)*100;
        printf("%d: %.2f%%\n",i,ans);
    }
    return 0;
}