#include<stdio.h>
#include<stdlib.h>
#define size 50
int front,rear,n,t;
struct queue
{
    int prior;
    int value;
}arr[size];
void sort() //bubble sort
{
    int i,j,t1,t2;
    for(i=0;i<t;i++)
    {
        for(j=0;j<t-1-i;j++)
        {
            if(arr[j].prior > arr[j+1].prior)
            {
                t1 = arr[j].prior;  //temp prior value
                t2 = arr[j].value;  //temp data value

                arr[j].prior = arr[j+1].prior;
                arr[j].value = arr[j+1].value;

                arr[j+1].prior = t1;    //swapping prior value
                arr[j+1].value = t2;    //swapping data value
            }
        }
    }
}
void display()
{
    sort();
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("|%d|%d|\t",arr[i].prior,arr[i].value);
    }
    printf("\n");
}
void enqueue(int v,int p)
{
    if(rear < n-1)
    {
        t++;
        rear++;
        arr[rear].prior = p;
        arr[rear].value = v;
        if(front < 0)
            front++;
    }
    else
        printf("Queue is FULL!!!\n");
}
int dequeue()
{
    int r = 0;
    if(rear < 0)
        return r;
    else
    {
        r = arr[rear].value;
        rear--;
        return r;
    }
}
int main()
{
    front = rear = -1;
    int a,v,p,d;
    printf("Enter the size of Queue : ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                printf("Enter the value of element : ");
                scanf("%d",&v);
                printf("Enter the priority of element : ");
                scanf("%d",&p);
                enqueue(v,p);
                display();
                break;
            case 2:
                d = dequeue();
                if(d != 0)
                {
                    printf("Popped element = %d\n",d);
                    display();
                }
                else
                    printf("Queue is EMPTY!!!\n");
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                exit(0);
        }
    }   
}