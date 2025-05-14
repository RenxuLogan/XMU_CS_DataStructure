#include<iostream>
#include<cmath>
using namespace std;
int len1=1;
int len2=1;
typedef struct node{
    int data;
    node* next;
}NODE;
int main(){
    NODE *head1 = new NODE;
    cin>>head1->data;
    NODE *p1 =new NODE;
    head1->next = p1;
    NODE *q1=new NODE;
    q1=head1;
    //p是下一节点，q是当前节点
    NODE *tail1=new NODE;
    while(true){
        cin>>p1->data;
        if(p1->data==-1){
            tail1=q1;
            q1->next = NULL;
            break;
        }
        if(p1->data==q1->data){
            continue;
        }
        q1->next = p1;
        q1=p1;
        len1++;
    }
    //initialize
    NODE *head2 = new NODE;
    cin>>head2->data;
    NODE *p2 =new NODE;
    head2->next = p2;
    NODE *q2=new NODE;
    q2=head2;
    //p是下一节点，q是当前节点
    NODE *tail2=new NODE;
    while(true){
        cin>>p2->data;
        if(p2->data==-1){
            tail2=q2;
            q2->next = NULL;
            break;
        }
        if(q2->data==p2->data){
            continue;
        }
        q2->next = p2;
        q2=p2;
        len2++;
    }
    //initialize
    int *array = new int[max(len1,len2)];
    int pin=0;
    NODE *temp1 = head1;
    NODE *temp2 = head2;
    while(temp1->next!=NULL && temp2->next!=NULL){
        if(temp1->data==temp2->data){
            array[pin]=temp1->data;
            pin++;
        }else if(temp1->data<temp2->data){
            temp1=temp1->next;
        }else if(temp1->data>temp2->data){
            temp2=temp2->next;
        }
    }
    if(pin==-1){
        cout<<"NULL";
    }else{
        for(int i=0;i<pin-1;i++){
            cout<<array[i]<<" ";
        }
        cout<<array[pin]<<endl;
    }
    return 0;
}