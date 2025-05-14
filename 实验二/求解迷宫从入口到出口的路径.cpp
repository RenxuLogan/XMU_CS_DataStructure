#include<iostream>
#include<vector>
using namespace std;
int maze[10][10];
int visited[10][10];
int n;

vector<int>result_x;
vector<int>result_y;

 bool dfs(int start_x,int start_y){
    if(start_x==n-2&&start_y==n-2){
        result_x.push_back(start_x);
        result_y.push_back(start_y);
        return true;
    }
    int dx[4] = {0, 1, 0, -1}; // x变化
    int dy[4] = {1, 0, -1, 0}; // y变化

    if(maze[start_x][start_y]==1||visited[start_x][start_y]){
        return false;
    }
    visited[start_x][start_y]=true;//将已访问过的
    result_x.push_back(start_x);
    result_y.push_back(start_y);
    //尝试4个方向
    for(int i=0;i<4;i++){
        int new_x=start_x+dx[i];
        int new_y=start_y+dy[i];
    
        if(new_x >= 1 && new_x < n-1 && new_y >= 1 && new_y < n-1){
            if(dfs(new_x,new_y)){
                return true;
            }
        }
    }

    result_x.pop_back();
    result_y.pop_back();
    return false;
    //回朔
 }
int main (){
    cin >> n; 
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> maze[i][j];
            visited[i][j] = false;
        }
    }
    int start_x=1,start_y=1;
    if(dfs(start_x,start_y)){
        while(!result_x.empty()){
            cout<<"("<<result_x.front()<<","<<result_y.front()<<")";
            result_x.erase(result_x.begin());
            result_y.erase(result_y.begin());        
        }
    }else{
        cout<<"NO";
    }
    return 0;
}