#include<iostream>

using namespace std;
typedef struct stuNode
{
    char id[14];
    int score;  //分数
    int text_place; //考场编号
    int rank_in_school; //学校排名
    int rank;   //考点排名

}student;
void HeapAdjust(student stu[],int k,int start,int end)
{
    stu[0]=stu[k];
    int i= k-start+1;
    int n = end-start + 1;
    for( ;i<=n;i*=2)
    {
        if( i<n &&( stu[start+i-1].score < stu[start+i].score || (stu[start+i-1].score == stu[i+start].score && strcmp(stu[start+i-1].id,stu[i+start].id)>0) )) i++;//比左右孩子中最大的小就要交换
        if(stu[start+i-1].score > stu[0].score|| (stu[start+i-1].score == stu[0].score && strcmp(stu[0].id,stu[start+i-1].id)>0) )
        {
            stu[k]=stu[start+i-1];
            k=start+i-1;
        }else break;
    }
    stu[k]=stu[0];
}

// 模版里的i是一个序列，多序列的或者说跟节点不是1的树（堆）就没有左右子树的索引=i*2、i*2+1的性质
void HeapSort_for_testPlace(student stu[],int start,int end)
{
    for(int i=end;i>=start;i--) HeapAdjust(stu,i,start,end);
    int count =1;
    for(int i=end;i>start;i--)
    {
        swap(stu[start],stu[i]);
        if(i!=end && stu[i].score==stu[i+1].score) stu[i].rank=stu[i+1].rank;
        else stu[i].rank=count;
        count++;
        HeapAdjust(stu,start,start,i-1);
    }
    if(end != start && stu[start].score==stu[start+1].score) stu[start].rank=stu[start+1].rank;
    else if(end==start) stu[start].rank=1;
    else if(stu[start].score!=stu[start+1].score)stu[start].rank=count;
}

void HeapSort_for_school(student stu[],int start,int end)
{
    for(int i=(end-start+1)/2;i>=start;i--) HeapAdjust(stu,i,start,end);
    int count =1;
    for(int i=end;i>start;i--)
    {
        swap(stu[start],stu[i]);
        if(i!=end && stu[i].score==stu[i+1].score) stu[i].rank_in_school=stu[i+1].rank_in_school;
        else stu[i].rank_in_school=count;
        count++;
        HeapAdjust(stu,start,start,i-1);
    }
    if(end != start && stu[start].score==stu[start+1].score) stu[start].rank_in_school=stu[start+1].rank_in_school;
    else if(end==start) stu[start].rank_in_school=1;
    else if(stu[start].score!=stu[start+1].score)stu[start].rank_in_school=count;
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
        HeapSort_for_testPlace(stu, text_stu_num[i-1]+1, text_stu_num[i] );
    }
 
    HeapSort_for_school(stu,1,text_stu_num[n]);
    cout<<text_stu_num[n]<<endl;
    for(int i=text_stu_num[n];i>=1;i--)cout<<stu[i].id<<" "<<stu[i].rank_in_school<<" "<<stu[i].text_place<<" "<<stu[i].rank<<endl; 
    return 0;
}