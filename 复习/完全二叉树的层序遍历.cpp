#include<iostream>

using namespace std;

int PostOrder[35];
int res[35];
int ind=1;
int n;
void postorder(int root)
{
    if(root >n) return ;
    postorder(2*root);
    postorder(2*root+1);
    res[root] = PostOrder[ind++];
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>PostOrder[i];
    }
    postorder(1);
    for(int i=1;i<=n;i++){
        if(i!=n) cout<<res[i]<<" ";
        else cout<<res[i];
    }
    return 0;
}