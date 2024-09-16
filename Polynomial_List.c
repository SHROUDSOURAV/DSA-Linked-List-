#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int co;
    int pow;
    struct node *next;
}node;
node *new_node,*trav;//global node* pointers
void Display(node *head)//display node in the list
{
    if(head == NULL)
        printf("LIST IS EMPTY!!!\n");
    else
    {
        trav = head;
        while(trav != NULL)
        {
            if(trav->next == NULL)
                printf("%dx^%d",trav->co,trav->pow);
            else
                printf("%dx^%d + ",trav->co,trav->pow);
            trav = trav->next;
        }
    }
}
node *Create()//allocate memory for new node
{
    node *new_node1;
    new_node1 = (node *)malloc(sizeof(node));
    printf("Enter the cofficient: ");
    scanf("%d",&new_node1->co);
    printf("Enter the power: ");
    scanf("%d",&new_node1->pow);
    new_node1->next = NULL;
    return new_node1;
}
node *Insert(node *head)//insert node in the list
{
    new_node = Create();
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
node *Create2(int co,int pow)//function for allocating memory to poly3 expression 
{
    node *new_node3;
    new_node3 = (node *)malloc(sizeof(node));
    new_node3->pow = pow;
    new_node3->co = co;
    new_node3->next = NULL;
    return new_node3;
}
node *Insert3(node *head3,int co,int pow)//function for traversing poly3 after head3 node
{
    node *new_node3,*trav3;
    new_node3 = Create2(co,pow);
    if(head3 == NULL)
        head3 = new_node3;
    else
    {
        trav3 = head3;
        while(trav3->next != NULL)
            trav3 = trav3->next;
        trav3->next = new_node3;
    }
    return head3;
}
node *Add(node *head1,node *head2,node *head3)//polynomial 1 and polynomial 2 addition function
{
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->pow > head2->pow)
        {
            head3 = Insert3(head3, head1->co, head1->pow);
            head1 = head1->next; 
        }
        else if(head2->pow > head1->pow)
        {
            head3 = Insert3(head3, head2->co, head2->pow);
            head2 = head2->next;
        }
        else
        {
            head3 = Insert3(head3, head1->co + head2->co, head1->pow);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    while(head1 != NULL || head2 != NULL)//loop for evaluating remaining poly1 or poly2 terms
    {
        if(head1 != NULL)
        {
            head3 = Insert3(head3, head1->co, head1->pow);
            head1 = head1->next;
        }
        if(head2 != NULL)
        {
            head3 = Insert3(head3, head2->co, head2->pow);
            head2 = head2->next;
        }
    }
    return head3;
}
int main()
{
    int a;
    char ch;
    node *head1 = NULL, *head2 = NULL, *head3 = NULL;//head1->poly1 head2->poly2 head3->poly3
    do
    {
        printf("1)Create Polynomial 1:\n");
        printf("2)Create Polynomial 2:\n");
        printf("3)Display Polynomial 1:\n");
        printf("4)Display Polynomial 2:\n");
        printf("5)Add Polynomial 1 and Polynomial 2:\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                head1 = Insert(head1);
                Display(head1);
            break;
            case 2:
                head2 = Insert(head2);
                Display(head2);
            break;
            case 3:
                Display(head1);
            break;
            case 4:
                Display(head2);
            break;
            case 5:
                head3 = NULL;
                head3 = Add(head1,head2,head3);
                Display(head3);
            break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}