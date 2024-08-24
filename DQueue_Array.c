#include<stdio.h>
#include<stdlib.h>
#define size 100
int a[size],front,rear;
void Display(int n)//function to display Dqueue elements
{
    int i;
    if(front == -1)
        printf("DQueue is EMPTY!!!\n");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",a[i]);
    }
    printf("\n");
}
void Enqueue_Rear(int data,int n)//function to insert element in Rear position
{
    if(rear < n-1)
    {
        a[++rear] = data;
        if(front < 0)
            front++;
    }
    else
        printf("DQueue is FULL!!!\nTry other insertion procedure\n");
}
void Enqueue_Front(int data,int n)//function to insert element in Front position
{
    if(front > 0)
        a[--front] = data;
    else
        printf("DQueue is FULL!!!\nTry other insertion procedure\n");
}
int Dequeue_Rear(int n)//function to delete element from Rear position
{
    int r;
    r = a[rear--];
    return r;
}
int Dequeue_Front()//function to delete element from Front position
{
    int r;
    if(front<=rear)
        r = a[front++];
    return r;
}
int main()
{
    front=rear=-1;
    int s;//switch variable
    int n;//size of Dqueue variable
    int data;//data insertion variable
    char ch;//loop variable
    printf("Enter the size of DQueue: ");
    scanf("%d",&n);
    do
    {
        printf("1.Enqueue Rear\n2.Enqueue Front\n3.Dequeue Front\n4.Dequeue Rear\n5.Display\nEnter your choice : ");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Enter the data to insert(Dqueue): ");
                scanf("%d",&data);
                Enqueue_Rear(data,n);
                Display(n);
                break;
            case 2:
                printf("Enter the data to insert:(Dqueue): ");
                scanf("%d",&data);
                Enqueue_Front(data,n);
                Display(n);
                break;
            case 3:
                if(front == -1)
                    printf("DQueue is EMPTY!!!\nTry other deletion procedure\n");
                else
                    printf("Popped element = %d\n",Dequeue_Front());
                    Display(n);
                break;
            case 4:
                if(front == -1)
                    printf("DQueue is EMPTY!!!\nTry other deletion procedure\n");
                else
                    printf("Popped element = %d\n",Dequeue_Rear(n));
                    Display(n);
                break;
            case 5:
                Display(n);
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
        printf("\nDo you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}