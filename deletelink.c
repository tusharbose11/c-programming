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
int length();
void display();
void delete();


void main()
{
    int ch;
    while(1)
    {
        printf("Single Linked List Operations \n");
        printf("1.Append\n ");
        printf("2.Length\n ");
        printf("3.Display\n ");
        printf("4.Delete\n ");
        printf("5.Quit\n ");

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
                case 4: delete(len);
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
void delete(len)
{
    struct node *temp,*temp2;
    int pos=1;

    {
        temp=root;
            while (len > 0) {

        if (pos % 2 == 0)
            {
                while(temp->link!=NULL){
                    root = temp->link;
                    temp->link=NULL;
                    free(temp);}
            }

                else
                {
                    printf("Elements deleted successfully.");
                    display();
                }
            len--;
            pos++;
            }
    }


}

