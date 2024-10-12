#include<stdio.h>   //priority queue using linked list
#include<stdlib.h>
typedef struct node
{
    int prior;
    int data;
    struct node *next;
}node;
node *new_node,*trav;
int count(node *head)   //Count nodes in the list
{
    int c = 0;
    if(head ==  NULL)
        return c;
    else
    {
        trav = head;
        c++;
        while(trav->next != NULL)
        {
            c++;
            trav = trav->next;
        }
        return c;
    }
}
void sort(node *head)   //bubble sort
{
    int c = count(head);
    int i,j,t1,t2;
    for(i=0;i<c;i++)
    {
        trav = head;
        for(j=0;j<c-1-i;j++)
        {
            if(trav->prior > trav->next->prior)
            {
                t1 = trav->prior;   //priority value
                t2 = trav->data;    //data value

                trav->prior = trav->next->prior;
                trav->data = trav->next->data;

                trav->next->prior = t1; //priority value swap
                trav->next->data = t2;  //data value swap
            }
            trav = trav->next;
        }
    }
}
void display(node *head)    //display list function
{
    if(head == NULL)
        printf("LIST IS EMPTY!!!\n");
    else
    {
        sort(head);
        trav = head;
        printf("Priority\tData\n");
        while(trav != NULL)
        {
            printf("%d\t\t%d\n",trav->prior,trav->data);
            trav = trav->next;
        }
    }
}
node *create()  //allocate memory and input data,priority in list
{
    node *new_node1;
    new_node1 = (node *)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d",&new_node1->data);
    printf("Enter the priority : ");
    scanf("%d",&new_node1->prior);
    return new_node1;
}
node *enqueue(node *head)   //insert node in the list(ascending order)
{
    new_node = create();
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
node *dequeue(node *head) //delete node in the list(highest priority)
{
    if(head == NULL)
        return head;
    else if(head->next == NULL)
    {
        new_node = head;
        head = NULL;
    }
    else
    {
        trav = head;
        while(trav->next->next != NULL)
            trav = trav->next;
        new_node = trav->next;
        trav->next = NULL;
    }
    free(new_node);
    return head;
}
int main()
{
    node *head = NULL;
    int a;  //switch variable
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                head = enqueue(head);
                display(head);
                break;
            case 2:
                head = dequeue(head);
                display(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
        }
    }
}