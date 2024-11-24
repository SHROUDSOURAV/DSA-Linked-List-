#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    struct list *next;
    int data;
}node;
node *new_node,*trav;
void display(node *head)
{
    if(head == NULL)
    {
        printf("List is empty!!!\n");
        return;
    }
    else
    {
        while(head != NULL)
        {
            printf("%d\t",head->data);
            head = head->next;
        }
        printf("\n");
    }
}
int count_node(node *head)
{
    int c = 0;
    if(head == NULL)
        return c;
    else
    {
        c = 1;
        while(head->next != NULL)
        {
            head = head->next;
            c++;
        }
        return c;
    }
}
node *create()
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d",&new_node->data);
    return new_node;
}
node *insert_last(node *head)
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
node *insert_first(node *head)
{
    new_node = create();
    if(head == NULL)
    {
        head = new_node;
        head->next = NULL;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    return head;
}
node *delete_first(node *head)
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
node *delete_last(node *head)
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
node *insert_position(node *head)
{
    int position,c;
    printf("Enter the position to insert node : ");
    scanf("%d",&position);
    if(position <= 0 || position > (count_node(head)+1))
        return head;
    else if(position == 1)
        return insert_first(head);
    else if(position == (count_node(head)+1))
        return insert_last(head);
    else
    {
        c = 1;
        trav = head;
        while(c < position-1)
        {
            c++;
            trav = trav->next;
        }
        new_node = create();
        new_node->next = trav->next;
        trav->next = new_node;
    }
    return head;
}
node *delete_position(node *head)
{
    int position,c;
    printf("Enter the position to delete node : ");
    scanf("%d",&position);
    if(position <= 0 || position > count_node(head))
        return head;
    else if(position == 1)
        return delete_first(head);
    else if(position == count_node(head))
        return delete_last(head);
    else
    {
        c = 1;
        trav = head;
        while(c < position-1)
        {
            c++;
            trav = trav->next;
        }
        new_node = trav->next;
        trav->next = new_node->next;
        free(new_node);
    }
    return head;
}
int main()
{
    int a,count;
    node *head = NULL;
    while(1)
    {
        printf("0.exit\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5.insert position\n6.delete position\n7.count nodes\n8.display\nEnter your choice : ");
        scanf("%d",&a);
        if(a == 0)
            break;
        switch(a)
        {
            case 1:
                head = insert_first(head);
                display(head);
                break;
            case 2:
                head = insert_last(head);
                display(head);
                break;
            case 3:
                head = delete_first(head);
                display(head);
                break;
            case 4:
                head = delete_last(head);
                display(head);
                break;
            case 5:
                head = insert_position(head);
                display(head);
                break;
            case 6:
                head = delete_position(head);
                display(head);
                break;
            case 7:
                count = count_node(head);
                printf("number of nodes = %d\n",count);
                break;
            case 8:
                display(head);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}