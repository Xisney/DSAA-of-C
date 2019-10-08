#include<stdio.h>
#include<stdlib.h>
//"设计一个算法，对单链表实现就地逆置"
typedef struct link
{
    int data;
    struct link *next;
} node;  // 定义节点

node* create_link(node* head,int data);
node *reverse_link(node* head);
int main()
{
    node *head = NULL;
    node*p;
    int i;
    for(i=0; i<10; i++)
    {
        head=create_link(head,i);
    }
    p=reverse_link(head);
    //p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}

node* create_link(node* head,int data)
{
    node *p,*pr=head;
    p = (struct link*)malloc(sizeof(struct link));
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr=pr->next;
        }
        pr->next=p;
    }
    p->data=data;
    p->next=NULL;
    return head;
}

//对单链表进行就地逆置
node *reverse_link(node* head)  // 对单链表进行逆置
{
    node *q,*pr,*p=head,*new_head;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    q=p;  // 将q设置为倒数第二个节点
    p=p->next;  // 将p设置为尾节点
    new_head=p;  // 将逆置后的头节点保存
    p->next=q;  // 将尾节点指向倒数第二个节点
    do
    {
        pr=head;
        while(pr->next->next!=p)  // 将pr设置为q前一个节点
        {
            pr=pr->next;
        }
        q=pr;
        p=p->next;  // 将p的位置设置为原q的位置
        p->next=q;  // 将p与q(即p前一个位置链接起来)
    }while(q!=head);
    q->next=NULL;  // 将原头节点置为尾节点
    return new_head;
}

