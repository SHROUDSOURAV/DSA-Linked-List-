#include<stdio.h>
#include<stdlib.h>
#define size 100
int front,rear;
int a[size];//array variable (global)
void Check(int n)//function to check queue is empty/full
{
    if(front == -1)
        printf("Queue is EMPTY!!!\n");
    else if(rear == n-1)
        printf("Queue is FULL!!!\n");
    else
        printf("Can PUSH/POP elements in Queue\n");
}
void Display(int n)//function to dislay queue elements
{
    int i;
    if(front == -1)
        printf("Queue is EMPTY!!!\n");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",a[i]);
    }
    printf("\n");
}
void Enqueue(int data,int n)//function to insert elements in queue
{
    if(rear < n-1)
    {
        a[++rear] = data;
        if(front < 0)
            front++;
    }
    else
        printf("Queue is FULL!!!\n");
}
int Dequeue()//function to delete queue elements
{
    int r;//show deleted element
    if(front > rear)//this condition specially proves the disadvantage of queue using (static array)
    {
        printf("FRONT HAS BECOME GREATER THAN REAR\nPLEASE RENTER THE SIZE OF QUEUE\n");
        r = a[front++];
    }
    if(front <= rear)
        r = a[front++];
    return r;
}
int main()
{
    front=rear=-1;
    int a;//switch variable
    char ch;//loop variable
    int n;//queue size input variable
    int data;//element to insert in queue 
    printf("Enter the size of the Queue : ");
    scanf("%d",&n);
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Check(Empty/FULL)\n4.Display\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)//switch case
        {
            case 1:
                printf("Enter the element to insert(queue): ");
                scanf("%d",&data);
                Enqueue(data,n);
                break;
            case 2:
                if(front == -1)
                    printf("Queue is EMPTY!!!\n");
                else
                    printf("Deleted element = %d",Dequeue());
                break;
            case 3:
                Check(n);
                break;
            case 4:
                Display(n);
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}