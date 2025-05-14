#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;

typedef struct stu
{
    string id;
    int kc;
    int kc_rank;
    int rank;
    int score;
}stu;

int c[120];
int cmp(const void *a,const void *b)
{
    const stu * p1=(const stu *)a;
    const stu * p2=(const stu *)b;
    if(p1->score == p2->score) return p1->id > p2->id ? 1 : -1 ;
    else return -p1->score + p2->score;

}
int main()
{
    memset(c ,0,sizeof(c));
    stu stu[10000];
    int n;cin>>n;
    for(int i=1 ; i<=n ;i++)
    {
        int num;cin>>num;
        c[i]=c[i-1]+num;

        for(int k=c[i-1];k<c[i];k++) cin>>stu[k].id>>stu[k].score;

        qsort( &stu[c[i-1]], num,sizeof(stu),cmp);

        int count = 2;
        for(int j=c[j-1];j<c[i];j++)
        {
            stu[j].kc = i;
            if(j==c[j-1]) stu[j].kc_rank=1;
            else if(stu[j].score==stu[j-1].score)
            {
                stu[j].kc_rank=stu[j-1].kc_rank;
                count ++;
            }
            else 
            {
                stu[j].kc_rank=count ++;
            }
        }
    }

    qsort(stu,c[n],sizeof(stu),cmp);
    int count =2;
    for(int i=0;i<c[n];i++)
    {
        if(i==0) stu[i].rank=1;
        else if(stu[i].score==stu[i-1].score)
        {
            stu[i].rank=stu[i-1].rank;
            count ++;
        }
        else 
        {
            stu[i].rank=count ++;
        }
    } 
    cout<<c[n]<<endl;
    for(int i=0;i<c[n];i++)  cout<<stu[i].id<<" "<<stu[i].rank<<" "<<stu[i].kc<<" "<<stu[i].kc_rank<<endl;
    return 0;
}