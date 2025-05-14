#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef struct pos
{
    int x;int y;
}pos;

int maze[15][15];
vector <pos> path;
int visited [15][15];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int dfs(int x,int y,int n)
{
    pos* position =new pos;
    position->x=x;
    position->y=y;
    path.push_back(*position);
    visited[x][y]=1;
    if(visited[n-2][n-2]==1) return 1;
    for(int i=0;i<4;i++)
    {
        int x_pos=x+dx[i];
        int y_pos=y+dy[i];
        if(x_pos<n && x_pos>0 && y_pos<n && y_pos>0 && maze[x_pos][y_pos]!=1 && visited[x_pos][y_pos]==0)
        {
            if(dfs(x_pos,y_pos,n)) return 1;
            visited[x_pos][y_pos]=0;
            path.pop_back();
        }
    }
    return 0;
}
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        memset(maze[i],0,sizeof(maze[i]));
        memset(visited[i],0,sizeof(visited[i]));
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    dfs(1,1,n);
    if(visited[n-2][n-2]==0)
    {
        cout<<"NO";
    }
    else
    {
        for(int i=0;i<path.size();i++)
        {
            cout<<"("<<path.at(i).x<<","<<path.at(i).y<<")";
        }
    }
    return 0;
}