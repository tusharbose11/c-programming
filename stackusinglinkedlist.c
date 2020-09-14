#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void traverse();
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL;
void push()
{
struct node* temp;
temp =(struct node*)malloc(sizeof(struct node));
printf("Enter data:\n");
scanf("%d",&temp->data);
temp->link=top;
top=temp;
}
void pop()
{
    struct node* temp;
    temp=top;
    if(top==NULL)
    {
        printf("No nodes to delete\n");
    }
    else
    {
        printf("Element %d",temp->data);
        top = top->link;
        temp->link=NULL;
        free(temp);
    }
}
void traverse()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
void main()
{
    int ch,item;
    while(1)
    {
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Traverse\n");
    printf("4.Quit\n");

    printf("Enter your choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: //printf("Enter the element:\n");
                //scanf("%d",&item);
                push();
                break;
        case 2: pop();
                break;
        case 3: traverse();
                break;
        case 4: exit(1);
                break;
        default: printf("Invalid Input.\n\n");

    }
    }
}
