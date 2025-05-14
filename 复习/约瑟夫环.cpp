#include<iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node * next;
}Node;
int main()
{
    int n,p;
    cin>>n>>p;
    Node *head = new Node;
    head->data=1;
    head->next=nullptr;
    Node *pre = head;
    for(int i=2;i<=n;i++)
    {
        Node *q =new Node;
        pre->next = q;
        q->data = i;
        pre=q;
    }
    pre->next=head;
    while(head->next != head)
    {
        for(int i = 1;i<p;i++)
        {
            pre=head;
            head=head->next;
        }
        //要去掉的是head这个节点
        pre->next=head->next;
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    return 0;
    

}
