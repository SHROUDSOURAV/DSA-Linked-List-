#include<stdio.h>
#include<stdlib.h>
struct Dqueue
{
    int data;
    struct Dqueue *next;
};
struct Dqueue *new_node,*traverse;//global struct Dqueue pointers
void Display(struct Dqueue *head)//function to display Dqueue elements
{
    if(head == NULL)
        printf("DQUEUE IS EMPTY!!!\n");
    else
    {
        traverse = head;
        while(traverse != NULL)
        {
            if(traverse->next == NULL)
                printf("%d|%d",traverse->data,traverse->next);
            else
                printf("%d|%d--->",traverse->data,traverse->next);
            traverse = traverse->next;
        }
    }
}
struct Dqueue *create_node()//function to allocate memory for new_node
{
    struct Dqueue *new_node;
    new_node = (struct Dqueue *)malloc(sizeof(struct Dqueue));
    printf("Enter the data : ");
    scanf("%d",&new_node->data);
    return new_node;
}
struct Dqueue *PUSH_REAR(struct Dqueue *head)//function to insert element in Rear position
{
    new_node = create_node();
    new_node->next = NULL;
    if(head == NULL)
        head = new_node;
    else
    {
        traverse = head;
        while(traverse->next != NULL)//traversing condition
            traverse = traverse->next;
        traverse->next = new_node;
    }
    return head;
}
struct Dqueue *PUSH_FRONT(struct Dqueue *head)//function to insert element in Front position
{
    new_node = create_node();
    if(head == NULL)
        new_node->next = NULL;
    else
        new_node->next = head;
    head = new_node;
    return head;
}
struct Dqueue *POP_FRONT(struct Dqueue *head)//function to delete element from Front position
{
    new_node = head;
    if(head == NULL)
        return head;
    else if(head->next == NULL)
        head = NULL;
    else
        head = head->next;
    free(new_node);
    return head;
}
struct Dqueue *POP_REAR(struct Dqueue *head)//function to delete element from Rear position
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
        while(traverse->next->next != NULL)//traversing condition
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
    struct Dqueue *head = NULL;//starting node connecting other nodes
    do
    {
        printf("1.PUSH REAR\n2.PUSH FRONT\n3.POP FRONT\n4.POP REAR\n5.DISPLAY\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                head = PUSH_REAR(head);
                Display(head);
                break;
            case 2:
                head = PUSH_FRONT(head);
                Display(head);
                break;
            case 3:
                head = POP_FRONT(head);
                Display(head);
                break;
            case 4:
                head = POP_REAR(head);
                Display(head);
                break;
            case 5:
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