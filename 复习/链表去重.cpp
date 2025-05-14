#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
typedef struct Node
{
    int data;
    struct Node* next;
    int index;
    int location;
}Node;

int remain_num[100005];
int tmp[100005][3];//分别存放 地址 键值 下一个结点地址

int main()
{
    int start,N,start_index;
    cin>>start>>N;
    for(int i=0;i<N;i++)
    {
        cin>>tmp[i][0]>>tmp[i][1]>>tmp[i][2];
        if(tmp[i][0]==start) start_index=i;
    }
    Node *head = new Node;
    head->data = tmp[start_index][1];
    head->index = start_index;
    head->location=tmp[start_index][0];
    Node * pre = head;

    for(int i=1;i<N;i++)
    {
        Node * tmpNode = new Node;
        pre->next = tmpNode;
        int j=0;
        for(;j<N;j++)
        {
            if(tmp[j][0] == tmp[pre->index][2] )break;
        }
        tmpNode->data = tmp[j][1];
        tmpNode->index = j;
        tmpNode -> location = tmp[j][0];
        pre=tmpNode;

    }

    pre->next = nullptr;
    Node * head2 =new Node;
    Node * p1 =head;
    Node * q1 =head;
    Node * q2 =head2;
    memset(remain_num,0,sizeof(remain_num));
    while(q1!=nullptr) 
    {
        if(remain_num[abs(q1->data)]) 
        {
            p1->next = q1->next;
            Node * tmpnode = new Node;
            tmpnode ->data=q1->data;
            tmpnode ->location=q1->location;
            tmpnode ->next=nullptr;
            q2->next=tmpnode;
            q2=tmpnode;
        }
        else 
        {
            remain_num[abs(q1->data)] = 1;
        }
        p1=q1;
        q1 = q1->next;
    }

    while(head->next!=nullptr)
    {
        cout<<setfill('0') << setw(5)<< head->location <<" "<< head->data <<" " <<setfill('0') << setw(5)<<head->next->location<<endl;
        head=head->next;
    }
    cout<< setfill('0') << setw(5)<<head->location <<" "<< head->data <<" " <<-1<<endl;
    head2=head2->next;
    while(head2->next!=nullptr)
    {
        cout<<setfill('0') << setw(5)<< head2->location <<" "<< head2->data <<" " <<setfill('0') << setw(5)<<head2->next->location<<endl;
        head2=head2->next;
    }
    cout<< head2->location <<" "<< head2->data <<" " <<-1<<endl;
    return 0;
}