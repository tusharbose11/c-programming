//Stack implementation using array(LIFO)
/*
Stack Operations
-Create // by static or dynamic memory
-push(int data) // insertion
-pop()  // deletion from top
-traverse // display
-isEmpty()
-isFull()
-size()
*/
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
void push(int);
int isFull();
int isEmpty();
int pop();
int peek();
void traverse();
int stack[CAPACITY];
int top = -1;
int isFull()
{
    if(top==CAPACITY-1)
    {
        return 1;
    }
    else
    {
            return 0;
    }
}
void push(int element)
{
    if(isFull())
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top]= element;
        printf("%d inserted \n", element);
    }
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop()
{
    int element;
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        element = stack[top];
        top--;
    }
    return top;
}
int peek()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top];
    }
}
void traverse()
{
    int i;
    if(isEmpty())
    {
        printf("No elements \n");
    }
    else
    {
        printf("Stack elements are \n");
        for(i=0;i<=top;i++)
        {
            printf("%d\n", stack[i]);
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
    printf("3.Peek\n");
    printf("4.Traverse\n");
    printf("5.Quit\n");

    printf("Enter your choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the element:\n");
                scanf("%d",&item);
                push(item);
                break;
        case 2: pop();
                break;
        case 3: peek();
                break;
        case 4: traverse();
                break;
        case 5: exit(1);
                break;
        default: printf("Invalid Input.\n\n");

    }
    }
}
