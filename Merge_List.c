#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *new_node,*traverse;//global struct node pointers
void Display(struct node *head)
{
    if(head == NULL)
        printf("List is EMPTY!!!\n");
    else
    {
        traverse = head;
        while(traverse != NULL)
        {
            if(traverse->next == NULL)
                printf("%d|%d",traverse->data,traverse->next);
            else
                printf("%d|%d-->",traverse->data,traverse->next);
            traverse = traverse->next;
        }
    }
}
struct node *Create()//allocate memory to list1,list2 and input data
{
    struct node *new_node1;
    new_node1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&new_node1->data);
    return new_node1;
}
struct node *Insert(struct node *head)
{
    new_node = Create();
    new_node->next = NULL;
    if(head == NULL)
        head = new_node;
    else
    {
        traverse = head;
        while(traverse->next != NULL)
            traverse = traverse->next;
        traverse->next = new_node;
    }
    return head;
}
struct node *Merge(struct node *head1,struct node *head2,struct node *head3)
{
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    else
    {
        head3 = head1;
        traverse = head3;
        while(traverse->next != NULL)
            traverse = traverse->next;
        traverse->next = head2;
    }
    return head3;
}
int main()
{
    int a;//switch variable
    char ch;//loop variable
    struct node *head1 = NULL;struct node *head2 = NULL;struct node *head3 = NULL;//list1 list2 list3 head nodes
    do
    {
        printf("1.Create List1\n2.Create List2\n3.Merge List3\n4.Display List1\n5.Display List2\n6.Display List3\nEnter your choice : ");
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
                head3 = Merge(head1,head2,head3);
                Display(head3);
                break;
            case 4:
                Display(head1);
                break;
            case 5:
                Display(head2);
                break;
            case 6:
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