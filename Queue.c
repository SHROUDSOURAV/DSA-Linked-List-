#include<stdio.h>
#include<stdlib.h>
struct queue 
{
    int data;
    struct queue *next;
};
struct queue *rear,*traverse;//global struct queue pointers
void Display(struct queue *front)//function to display elements in Queue
{
    if(front == NULL)
        printf("Queue is EMPTY!!!\n");
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
struct queue *create_node()
{
    struct queue *rear;
    rear = (struct queue *)malloc(sizeof(struct queue));//allocating memory for new_node insertion
    printf("Enter the data to insert(queue): ");
    scanf("%d",&rear->data);
    return rear;
}
struct queue *enqueue(struct queue *front)//function to insert element in Queue
{
    rear=create_node();
    rear->next = NULL;
    if(front == NULL)
        front = rear;
    else
    {
        traverse=front;
        while(traverse->next != NULL)//traversing queue until it reaches last element
            traverse=traverse->next;
        traverse->next=rear;//inserting new element 
    }
    return front;
}
struct queue *dequeue(struct queue *front)//function to delete element in Queue
{
    if(front == NULL)
        return front;
    else
    {
        rear=front;//copying front address to rear
        front=front->next;//switching the starting node
        free(rear);//freeing the previous front memory(starting node)
        return front;
    }
}
int main()
{
    int a;//switch variable
    char ch;//loop condition variable
    struct queue *front = NULL;//starting node connecting other nodes
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                front=enqueue(front);//updating front during element insertion
                Display(front);
                break;
            case 2:
                front=dequeue(front);//updating front during element insertion
                Display(front);
                break;
            case 3:
                Display(front);//displaying queue elements
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'Y' || ch == 'y');
    return 0;
}