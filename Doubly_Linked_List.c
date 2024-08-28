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
struct node *Delfa(struct node *head)
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
struct node *Della(struct node *head)
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