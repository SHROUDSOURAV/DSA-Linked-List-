#include<stdio.h>//NOTE: I have only reversed the linked list using recursion. The original list is unaffected.
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *new_node,*traverse;//global struct node pointers
void Normal_Display(struct node *head)//function to display List head node--->last node
{
    if(head == NULL)
        printf("List is EMPTY!!!\n");
    else
    {
        traverse = head;
        while(traverse != NULL)
        {
            printf("%d\t",traverse->data,traverse->next);
            traverse=traverse->next;
        }
    }
}
void Reverse_Display(struct node *head)//function to display list from last node-->head node
{
    if(head == NULL)
        return;
    else
    {
        Reverse_Display(head->next);
        printf("%d\t",head->data);
    }
}
struct node *create_node()//function to allocate memory for creating node
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));//allocate memory for node insertion
    printf("Enter the data to insert(linked list): ");
    scanf("%d",&new_node->data);
    return new_node;
}
struct node *Insert(struct node *head)//function to insert node and traverse
{
    new_node = create_node();
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
int main()
{
    int a;//switch variable
    char ch;//loop variable
    struct node *head = NULL;//starting node connecting other nodes
    do
    {
        printf("1.Create\n2.Noramal Display\n3.Reverse Display\nEnter your choice: ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                head=Insert(head);
                Normal_Display(head);
                printf("\n");
                break;
            case 2:
                Normal_Display(head);
                printf("\n");
                break;
            case 3:
                Reverse_Display(head);
                printf("\n");
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
