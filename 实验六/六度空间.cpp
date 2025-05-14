#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int bfs(int array[][1001],int n,int start){
    int count=0;int sum=0;//count是层数，sum是有多少个结点
    queue<int> q;
    q.push(start);
    int visit[1001]={0};
    visit[start]=1;

    int num[8]={0};
    num[count]=1;
    int level_count=0;
    int pre_sum=0;
    while(!q.empty() && count < 6){
        int temp=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(array[temp][i]==1 && visit[i]==0){
                
                visit[i]=1;
                sum++;
                q.push(i);
            }
        }

        level_count++;
        if(level_count==num[count]){
            num[++count]=sum-pre_sum;
            pre_sum=sum;
            level_count=0;

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