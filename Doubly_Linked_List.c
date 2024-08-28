#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *new_node,*traverse;
void Display(struct node *head)
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
struct node *create_node()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&new_node->data);
    return new_node;
}
struct node *create_list(struct node *head)
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
struct node *new_node,*traverse;
int main()
{
    int a;
    char ch;
    struct node *head = NULL;
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