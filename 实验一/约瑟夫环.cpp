#include<iostream>
using namespace std;
int n,pin,len;
typedef struct node{
    int data;
    struct node *next;
}NODE;
int main(){
    cin>>n>>pin;
    NODE *HeadNode=new NODE;
    HeadNode->data=1;
    HeadNode->next=NULL;
    len++;
    //初始化头节点
    NODE *temp=new NODE;
    temp=HeadNode;
    NODE *TailNode = new NODE;
    for(int i=2;i<=n;i++){
        NODE *cur=new NODE;
        cur->data=i;
        temp->next=cur;
        temp=cur;
        len++;
    }
    temp->next=HeadNode;
    TailNode=temp;

    //initialization

    NODE *p=new NODE;
    NODE *q=new NODE;

    p=TailNode;
    q=p->next;
    while(len>1){
        int count = 1;
        while(count<pin){
            p=q;
            q=q->next;
            count++;
        }
        cout<<q->data<<" ";
        p->next=q->next;
        q=p->next;
        len--;
    }
    cout<<p->data;
    cout<<endl;
    return 0;
}
//关键：引用len来表示链表长度从而减少对与头尾节点的操作
