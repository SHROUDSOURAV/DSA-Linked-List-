#include<stdio.h>
#include<stdlib.h>
struct Cqueue
{
    int data;
    struct Cqueue *next;
};
struct Cqueue *rear,*traverse;//global struct Cqueue pointers
void Display(struct Cqueue *front)//function to display elements in Circular Queue
{
    if(front == NULL)
        printf("Circular Queue is EMPTY!!!\n");
    else
    {
        traverse=front;
        printf("%d|%d(front)-->",traverse->data,traverse->next);
        traverse=traverse->next;
        while(traverse != front)
        {
            if(traverse->next == front)
                printf("%d|%d(rear)",traverse->data,traverse->next);
            else
                printf("%d|%d-->",traverse->data,traverse->next);
            traverse=traverse->next;
        }
    }
}
struct Cqueue *create_node()//function to create memory space for element insertion in Circular Queue
{
    struct Cqueue *rear;
    rear = (struct Cqueue *)malloc(sizeof(struct Cqueue));//allocate memory to insert elements
    printf("Enter the data to insert(Cqueue):");
    scanf("%d",&rear->data);
    return rear;
}
struct Cqueue *enqueue(struct Cqueue *front)//function to insert elements in Circular Queue and traverse
{
    rear = create_node();
    if(front == NULL)
    {
        front = rear;
        front->next = front;
    }
    else
    {
        traverse = front;
        while(traverse->next != front)
            traverse=traverse->next;
        traverse->next = rear;
        rear->next = front;
    }
    return front;
}
struct Cqueue *dequeue(struct Cqueue *front)//function to delete elements in Circular Queue 
{
    if(front == NULL)
        return front;
    else if(front->next == front)
    {
        rear = front;
        front = NULL;
    }
    else
    {
        rear=traverse=front;
        while(traverse->next != front)
            traverse=traverse->next;
        traverse->next=front->next;
        front=front->next;
    }
    free(rear);
    return front;
}
int main()
{
    int a;//switch variable
    char ch;//loop variable
    struct Cqueue *front = NULL;//head node connecting other nodes
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                front=enqueue(front);
                Display(front);
                break;
            case 2:
                front=dequeue(front);
                Display(front);
                break;
            case 3:
                Display(front);
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while(ch == 'Y' || ch == 'y');
    return 0;
}