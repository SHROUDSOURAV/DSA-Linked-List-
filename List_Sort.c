#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *new_node,*trav;
int Count(node *head)
{
    int c = 0;
    if(head == 0)
        return c;
    else
    {
        c++;
        trav = head;
        while(trav->next != NULL)
        {
            trav = trav->next;
            c++;
        }
        return c;
    }
}
void Bubble_Sort(node *head)
{
    int i = 0,j = 0,count = 0,temp = 0;
    count = Count(head);
    for(i = 0; i < count; i++)
    {    
        trav = head;
        for(j = 0; j < count-i-1; j++)
        {
            if(trav->data > trav->next->data)
            {
                temp = trav->data;
                trav->data = trav->next->data;
                trav->next->data = temp;
            }
            trav = trav->next;
        }
    }
}
void Display(node *head)
{
    if(head == NULL)
        printf("LIST IS EMPTY!!!\n");
    else
    {
        Bubble_Sort(head);
        trav = head;
        while(trav != NULL)
        {
            if(trav->next == NULL)
                printf("%d|%d",trav->data,trav->next);
            else
                printf("%d|%d-->",trav->data,trav->next);
            trav = trav->next;
        }
    }
}
node *Create()
{
    node *new_node1;
    new_node1 = (node *)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d",&new_node1->data);
    return new_node1;
}
node *Insert(node *head)
{
    new_node = Create();
    new_node->next = NULL;
    if(head == NULL)
        head = new_node;
    else
    {
        trav = head;
        while(trav->next != NULL)
            trav = trav->next;
        trav->next = new_node;
    }
    return head;
}
int main()
{
    int a;//switch variable
    char ch;//loop vairable
    node *head = NULL;
    do
    {
        printf("1.Insert Node\n2.Display\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                head = Insert(head);
                Display(head);
                break;
            case 2:
                Display(head);
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
