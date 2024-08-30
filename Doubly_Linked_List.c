#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *new_node,*traverse;
void Display(struct node *head)//function to display list elements
{
    if(head == NULL)
        printf("LIST IS EMPTY!!!\n");
    else
    {
        traverse = head;
        while(traverse != NULL)
        {
            if(traverse->next == NULL)
                printf("%d|%d|%d",traverse->prev,traverse->data,traverse->next);
            else
                printf("%d|%d|%d-->",traverse->prev,traverse->data,traverse->next);
            traverse = traverse->next;
        }
    }
}
int Count(struct node *head)//function to count the number of nodes in the list
{
    int c=0;
    if(head == NULL)
        return c;
    else
    {
        c++;
        traverse = head;
        while(traverse->next != NULL)
        {
            c++;
            traverse = traverse->next;
        }
        return c;
    }
}
struct node *create_node()//allocate memory for node insertion
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&new_node->data);
    return new_node;
}
struct node *create_list(struct node *head)//function to create the linked list and traverse
{
    new_node = create_node();
    new_node->next = NULL;
    if(head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
    }
    else
    {
        traverse = head;
        while(traverse->next != NULL)
            traverse = traverse->next;
        traverse->next = new_node;
        new_node->prev = traverse;
    }
    return head;
}
struct node *Infa(struct node *head)//function to insert element at the beginning of the list
{
    new_node = create_node();
    new_node->prev = NULL;
    if(head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return head;
}
struct node *Delfa(struct node *head)//function to delete element from the head node/starting position
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
        new_node = head;
        head = head->next;
    }
    free(new_node);
    return head;
}
struct node *Della(struct node *head)//function to delete the last node/last element of the list
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
        traverse = head;
        while(traverse->next->next != NULL)
            traverse = traverse->next;
        new_node = traverse->next;
        traverse->next = NULL;
    }
    free(new_node);
    return head;
}
struct node *Inpo(struct node *head)//function to insert node at user specified position in the list
{
    int position,count = 0;
    printf("Enter the position : ");
    scanf("%d",&position);
    if(position <= 0 || position > (Count(head)+1))
    {
        printf("INVALID POSITION!!!\n");
        return head;
    }
    else if(position == 1)
        return Infa(head);
    else if(position == (Count(head)+1))
        return create_list(head);
    else
    {
        count++;
        traverse = head;
        while(count < position-1)
        {
            count++;
            traverse = traverse->next;
        }
        new_node = create_node();
        new_node->next = traverse->next;
        traverse->next = new_node;
        new_node->prev = traverse;
        traverse = new_node->next;
        traverse->prev = new_node;
        return head;
    }
}
struct node *Delpo(struct node *head)
{
    int position,c=0;
    struct node *trav2;//local struct node pointer
    if(head == NULL)
        return head;
    printf("Enter the position : ");
    scanf("%d",&position);
    if(position <=0 || position > Count(head))
    {
        printf("INVALID POSITION!!!\n");
        return head;
    }
    else if(position == 1)
        return Delfa(head);
    else if(position == Count(head))
        return Della(head);
    else
    {
        c++;
        traverse = head;
        while(c < position - 1)
        {
            c++;
            traverse = traverse->next;
        }
        new_node = traverse->next;
        traverse->next = new_node->next;
        trav2 = new_node->next;
        trav2->prev = traverse;//after delete changing previous node location
        free(new_node);
        return head;
    }
}
int main()
{
    int a;//switch variable
    char ch;//loop variable
    struct node *head = NULL;//head node/starting node connecting other nodes
    do
    {
        printf("1.Create\n");
        printf("2.Insert First\n");
        printf("3.Insert Last\n");
        printf("4.Delete First\n");
        printf("5.Delete Last\n");
        printf("6.Insert Position\n");
        printf("7.Delete Position\n");
        printf("8.Display\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                head = create_list(head);
                Display(head);
                break;
            case 2:
                head = Infa(head);
                Display(head);
                break;
            case 3:
                head = create_list(head);
                Display(head);
                break;
            case 4:
                head = Delfa(head);
                Display(head);
                break;
            case 5:
                head = Della(head);
                Display(head);
                break;
            case 6:
                head = Inpo(head);
                Display(head);
                break;
            case 7:
                head = Delpo(head);
                Display(head);
                break;
            case 8:
                Display(head);
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %s",&ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}