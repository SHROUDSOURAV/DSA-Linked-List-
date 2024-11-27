#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
char b[size][50];
int n,top = -1;
void push(char a[])
{
    if(top == n-1)
    {
        printf("Stack is Full!!!\n");
        return;
    }
    strcpy(b[++top],a);
    strrev(b[top]);
}
void pop()
{
    if(top == -1)
    {
        printf("Stack is Empty!!!\n");
        return;
    }
    printf("Popped string = %s\n",b[top--]);
}
void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is Empty!!!\n");
        return;
    }
    for(i=top;i>=0;i--)
        printf("%s\t",b[i]);
    printf("\n");
}
int main()
{
    int s;
    char a[size];
    printf("Enter the size of stack : ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n0.exit\n1.insert string\n2.Delete string\n3.Reverse string display\nEnter your choice : ");
        scanf("%d",&s);
        if(s == 0)
            break;
        switch(s)
        {
            case 1:
                printf("Enter the string : ");
                scanf("%s",a);
                push(a);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
}