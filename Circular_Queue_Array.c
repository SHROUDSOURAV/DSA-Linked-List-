#include<stdio.h>
#define size 100
int a[size],n,front=-1,rear=-1;
void enqueue(int data)
{
    if((rear+1)%n == front)
    {
        printf("Queue is Full!!!\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear = (rear+1)%n;
    a[rear] = data;
}
int dequeue()
{
    int data;
    if(front == -1)
        data = front;
    else
    {
        data = a[front];
        if(front == rear)
            front = rear = -1;
        else
            front = (front+1)%n;
    }
    return data;
}
void display()
{
    int i;
    if(front <= rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",a[i]);
    }
    else
    {
        for(i=front;i<n;i++)
            printf("%d\t",a[i]);
        for(i=0;i<=rear;i++)
            printf("%d\t",a[i]);
    }
    printf("\n");
}
int main()
{
    int s,data;
    printf("Enter the size of Queue : ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\nEnter your choice : ");
        scanf("%d",&s);
        if(s == 0)
            break;
        switch(s)
        {
            case 1:
                printf("Enter the data to insert : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if(data == -1)
                    printf("Queue is Empty!!!\n");
                else
                    printf("Deleted element = %d",data);
                break;
            case 3:
                display();
                break;
        }
    }
}