#include<stdio.h>
#include<stdlib.h>
struct deque 
{
    int data;
    struct deque *next;
};
struct deque *rear,*traverse;//global struct deque pointers
void Display(struct deque *front)//function to display deque elements
{
    if(front == NULL)
        printf("Deque is EMPTY!!!\n");
    else
    {
        traverse=front;
        printf("%d|%d(front)-->",traverse->data,traverse->next);
        traverse=traverse->next;
        while(traverse != NULL)
        {
            if(traverse->next == NULL)
                printf("%d|%d(rear)",traverse->data,traverse->next);
            else
                printf("%d|%d-->",traverse->data,traverse->next);
            traverse=traverse->next;
        }
    }
}
struct deque *create_node()//function to create_node
{
    struct deque *rear;
    rear = (struct deque *)malloc(sizeof(struct deque));//allocate memory for element insertion
    printf("Enter the data (dqueue): ");
    scanf("%d",&rear->data);
    return rear;
}
struct deque *push_front(struct deque *front)//function to insert elements from front positon
{
    rear=create_node();
    if(front == NULL)
    {
        rear->next=NULL;
        front=rear;
    }
    else
    {
        rear->next=front;
        front=rear;
    }
    return front;
}
struct deque *push_rear(struct deque *front)//function to insert elements from rear position
{
    rear = create_node();
    rear->next = NULL;
    if(front == NULL)
        front = rear;
    else
    {
        traverse = front;
        while(traverse->next != NULL)
            traverse=traverse->next;
        traverse->next = rear;
    }
    return front;
}
struct deque *pop_front(struct deque *front)//function to delete elements from front position
{
    if(front == NULL)
        return front;
    else
    {
        rear=front;
        front=front->next;
        free(rear);//freeing the memory allocated to the node to delete
        return front;
    }
}
struct deque *pop_rear(struct deque *front)//function to delete elements from rear position
{
    if(front == NULL)
        return front;
    else if(front->next == NULL)
    {
        rear=front;
        front=NULL;
    }
    else
    {
        traverse=front;
        while(traverse->next->next != NULL)
            traverse=traverse->next;
        rear=traverse->next;
        traverse->next=NULL;
    }
    free(rear);//freeing the memory allocated to the node to delete
    return front;
}
int main()
{
    int a;//switch variable
    char ch;//loop variable
    struct deque *front = NULL;//starting node to connect other nodes/elements in deque
    do
    {
        printf("1.Push_Front\n2.Push_Rear\n3.Pop_Front\n4.Pop_Rear\n5.Display\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                front=push_front(front);
                Display(front);
                break;
            case 2:
                front=push_rear(front);
                Display(front);
                break;
            case 3:
                front=pop_front(front);
                Display(front);
                break;
            case 4:
                front=pop_rear(front);
                Display(front);
                break;
            case 5:
                Display(front);
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'Y' || ch == 'y');
    return 0;
}