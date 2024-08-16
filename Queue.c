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

}
struct queue *dequeue(struct queue *front)//function to delete element in Queue
{

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
        printf("Do you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'Y' || ch == 'y');
    return 0;
}