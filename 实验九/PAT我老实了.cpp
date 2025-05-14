#include<iostream>
#include<cstring>

using namespace std;
typedef struct stuNode
{
    char id[14];
    int score;  //分数
    int text_place; //考场编号
    int rank_in_school; //学校排名
    int rank;   //考点排名

}student;
void Sort_for_place(student stu[],int start,int end)
{

    int count =1;
    for(int i=end;i>start;i--)
    {
        for(int j=start;j<i;j++)
        {
            if(stu[j].score>stu[j+1].score || stu[j].score==stu[j+1].score && strcmp(stu[j].id,stu[j+1].id) <0 )  swap(stu[j],stu[j+1]);
        }
        if(i!=end && stu[i].score==stu[i+1].score)
        {
            stu[i].rank=stu[i+1].rank;
        }else
        {
            stu[i].rank=count;
        }
        count++;
    }
    if(stu[start].score==stu[start+1].score) stu[start].rank=stu[start+1].rank;
    else stu[start].rank=count;

}
void Sort_for_shool(student stu[],int start,int end)
{
    int count =1;
    for(int i=end;i>start;i--)
    {
        for(int j=start;j<i;j++)
        {
            if(stu[j].score>stu[j+1].score || stu[j].score==stu[j+1].score && strcmp(stu[j].id,stu[j+1].id) <0 )  swap(stu[j],stu[j+1]);
        }
        if(i!=end && stu[i].score==stu[i+1].score)
        {
            stu[i].rank_in_school=stu[i+1].rank_in_school;
        }else
        {
            stu[i].rank_in_school=count;
        }
        count++;
    }
    if(stu[start].score==stu[start+1].score) stu[start].rank_in_school=stu[start+1].rank_in_school;
    else stu[start].rank_in_school=count;

}
int main()
{
    int n;
    cin>>n;
    student stu[3010];
    int text_stu_num[105]={0};
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        int start = text_stu_num[i-1];
        for(int j=1;j<=k;j++)
        {
            cin>>stu[start+j].id >> stu[start+j].score;
            stu[start+j].text_place=i;
        }
        text_stu_num[i]=text_stu_num[i-1]+k;
        Sort_for_place(stu, text_stu_num[i-1]+1, text_stu_num[i] );
    }
    cout<<text_stu_num[n]<<endl;
/*
     HeapSort_for_school(stu,1,text_stu_num[n]);
    cout<<text_stu_num[n]<<endl;
*/
    Sort_for_shool(stu,1,text_stu_num[n]);
    for(int i=text_stu_num[n];i>=1;i--)cout<<stu[i].id<<" "<<stu[i].rank_in_school<<" "<<stu[i].text_place<<" "<<stu[i].rank<<endl; 
  
    return 0;
}