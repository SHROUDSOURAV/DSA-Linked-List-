#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void display(node *head)//display node in the list
{
    node *trav1;
    if(head == NULL)
        printf("LIST IS EMPTY!!!\n");
    else
    {
        trav1 = head;
        while(trav1 != NULL)
        {
            if(trav1->next == NULL)
                printf("%d|%d",trav1->data,trav1->next);
            else
                printf("%d|%d-->",trav1->data,trav1->next);
            trav1 = trav1->next;
        }
    }
}
node *create()//allocate memory to list1 and list2 nodes
{
    node *new_node1;
    new_node1 = (node *)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d",&new_node1->data);
    return new_node1;
}
node *insert(node *head)//insert nodes in list 1 and list 2
{
    node *new,*t;
    new = create();
    new->next = NULL;
    if(head == NULL)
        head = new;
    else
    {
        t = head;
        while(t->next != NULL)
            t = t->next;
        t->next = new;
    }
    return head;
}
node *create3()
{
    node *new_node3;
    new_node3 = (node *)malloc(sizeof(node));
    new_node3->next = NULL;
    return new_node3;
}
node *append(node *head1,node *head2,node *head3)
{
    node *t1,*t2,*t3;
    if(head1 == NULL)
    {
        head3 = create3();
        head3->data = head2->data;
        t3 = head3;
        t2 = head2;
        while(t2->next != NULL)
        {
            t2 = t2->next;
            t3->next = create3();
            t3->next->data = t2->data;
            t3 = t3->next;
        }
        return head3;
    }
    if(head2 == NULL)
    {
        head3 = create3();
        head3->data = head1->data;
        t3 = head3;
        t1 = head1;
        while(t1->next != NULL)
        {
            t1 = t1->next;
            t3->next = create3();
            t3->next->data = t1->data;
            t3 = t3->next;
        }
        return head3;
    }
    else
    {
        head3 = create3();
        head3->data = head1->data;
        t1 = head1;
        t3 = head3;
        while(t1->next != NULL)
        {
            t1 = t1->next;
            t3->next = create3();
            t3->next->data = t1->data;
            t3 = t3->next;
        }
        t2 = head2;
        t3->next = create3();
        t3->next->data = t2->data;
        while(t2->next != NULL)
        {
            t2 = t2->next;
            t3->next = create3();
            t3->next->data = t2->data;
            t3 = t3->next;
        }
        return head3;
    }
}
int main()
{
    int a;//switch variable;
    node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    while(1)
    {
        printf("\n");
        printf("1.Insert List 1\n");
        printf("2.Insert List 2\n");
        printf("3.Append List 3\n");
        printf("4.Display List 1 and List 2\n");
        printf("5.Display List 3\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                head1 = insert(head1);
                display(head1);
                break;
            case 2:
                head2 = insert(head2);
                display(head2);
                break;
            case 3:
                head3 = NULL;
                head3 = append(head1,head2,head3);
                display(head3);
                break;
            case 4:
                printf("LIST 1:\n");
                display(head1);
                printf("\nLIST 2:\n");
                display(head2);
                break;
            case 5:
                printf("LIST 3:\n");
                display(head3);
                break;
            case 6:
                exit(0);
            default:
                printf("INVALID CHOICE!!!\n");
        }
    }
    return 0;
}