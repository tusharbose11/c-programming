//Singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL;
int len=0;
void append();
void addatbegin();
void addatafter();
int length();
void display();
void delete();


void main()
{
    int ch;
    while(1)
    {
        printf("Single Linked List Operations \n");
        printf("\t1.Append\n ");
        printf("\t2.Length\n ");
        printf("\t3.Display\n ");
        printf("\t4.Delete\n ");
        printf("\t5.Quit\n ");

        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
            {
                case 1: append();
                        break;
                case 2: len = length();
                        printf("Length = %d \n",len);
                        break;
                case 3: display();
                        break;
                case 4: delete();
                        break;
                case 5: exit(1);
                default: printf("Invalid Input");
            }
    }
}

void append()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d", &temp->data);
    temp->link=NULL;
    if(root==NULL)
        {
            root=temp;
        }
    else
        {
            struct node *temp2;
            temp2 = root;
            while(temp2->link != NULL)
            {
                temp2 = temp2->link;
            }
          temp2->link =temp;
        }
}

int length()
{
    struct node *temp;
    int count = 0;
    temp = root;

    while(temp!=NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}
void display()
{
    struct node *temp;
    temp = root;
    if(temp==NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}

void addatbegin()
{
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d", &temp->data);
    temp->link=root;
    root=temp;

}
void addatafter()
{
    struct node *temp,*temp2;
    int loc,len,i=1;
    printf("Enter location: \n");
    scanf("%d", &loc);
    len = length();
    if(loc>len)
    {
        printf("Invalid Location.\n");
        printf("Currently List is having %d nodes.\n",len);
    }
    else
    {
        temp2=root;
        while(i<loc)
        {
            temp2= temp2->link;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: \n");
        scanf("%d", &temp->data);
        temp->link=NULL;
        temp->link=temp2->link;
        temp2->link=temp;
    }
}
void delete()
{
    struct node *temp;
    int loc;
    printf("Enter location to delete:\n");
    scanf("%d", &loc);
    if(loc>length())
    {
        printf("Invalid Location\n");
    }
    else if(loc==1)
    {
        temp=root;
        root = temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        int i = 1;
        struct node *temp2, *temp3;
        temp2 = root;
        while(i<loc-1)
        {
            temp2=temp2->link;
            i++;
        }
        temp3=temp2->link;
        temp2=temp3->link;
        temp3->link=NULL;
        free(temp3);
    }
}

