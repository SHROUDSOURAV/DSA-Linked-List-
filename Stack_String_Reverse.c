#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
char b[size][size];
int n,top=-1;
void push(char a[])
{
    int i,j=0,l=0;
    if(top == n-1)
    {
        printf("stack is full!!!\n");
        return;
    }
    top++;
    l = strlen(a)-1;
    for(i=l;i>=0;i--)
    {
        b[top][j] = a[i];
        j++;
    }
    b[top][j] = '\0';
}
void pop()
{
    if(top == -1)
    {
        printf("stack is empty!!!\n");
        return;
    }
    printf("popped element = %s\n",b[top--]);
}
void display()
{
    int i;
    if(top == -1)
    {
        printf("stack is empty!!!\n");
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
        printf("\n0.exit\n1.push\n2.pop\n3.display\nEnter your choice : ");
        scanf("%d",&s);
        if(s == 0)
            break;
        switch(s)
        {
            case 1:
                printf("Enter string : ");
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
                printf("invalid choice!!!\n");
        }
    }
    return 0;
}