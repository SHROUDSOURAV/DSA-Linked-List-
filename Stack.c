#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;//containing stack elements
    struct stack *next;//points to address of next stack element
};
struct stack *new_node,*traverse;//global struct stack type pointers
struct stack *create_node()
{
    struct stack *new_node;
    new_node = (struct stack *)malloc(sizeof(struct stack));//allocating memory using malloc() for new_node insertion
    printf("Enter the data to insert(stack) : ");
    scanf("%d",&new_node->data);
    return new_node;
}
int Check_Empty(struct stack *start)//function to check whether stack is empty or not
{
    if(start == NULL)
        return 0;
    else 
        return 1;
}
void Display(struct stack *start)//display stack elements in reverse order(like stack)
{
    if(start == NULL)
        return;
    else
    {
        Display(start->next);
        printf("%d\n",start->data);
    }
} 
struct stack *Push(struct stack *start)//function to insert/push element in stack
{
    new_node = create_node();
    new_node->next = NULL;
    
    if(start == NULL)
        start=new_node;//if start is null new_node = starting node
    else
    {
        traverse=start;
        while(traverse->next != NULL)//pointer will traverse until it hits last node
            traverse = traverse->next;
        traverse->next = new_node;//allocating new last node
    }
    return start;
}
struct stack *Pop(struct stack *start)//function to delete/pop element from stack
{
    if(start == NULL)
        return start;
    else if(start->next == NULL)
    {
        new_node = start;//copying start node to new_node
        start = NULL;
    }
    else
    {
        traverse=start;
        while(traverse->next->next != NULL)//checking last node , one node before
            traverse=traverse->next;
        new_node = traverse->next;//copying the address of last node
        traverse->next = NULL;//cutting connection of with last node
    }
    free(new_node);//freeing the memory allocated to the node to delete
    return start;
}
int main()
{
    int a;//switch variable
    char ch;//for looping condition
    struct stack *start = NULL;//pointer for starting node(connecting other nodes)
    do
    {
        printf("1.Push\n2.Pop\n3.Display\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                start=Push(start);//updating starting node to make changes in linked list(stack)
                Display(start);
                break;
            case 2:
                if(Check_Empty(start) == 1)
                {
                    start=Pop(start);//updating starting node to make changes in linked list(stack)
                    Display(start);
                }
                else
                    printf("Stack is EMPTY!!!\n");
                break;
            case 3:
                if(Check_Empty(start) == 1)
                    Display(start);//display stack
                else
                    printf("Stack is EMPTY!!!\n");
                break;
            default:
                printf("INVALID CHOICE\n");
        }
        printf("Do you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'Y' || ch == 'y');
    return 0;
}

