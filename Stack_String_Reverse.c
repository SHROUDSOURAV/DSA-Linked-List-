#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
int top,n;
char store[size][50];   //stores string/words in respective index positions
char a[size];   //input string/word
void push(char a[])
{
    if(top == n-1)
        printf("Stack is Full!!!\n");
    else
        strcpy(store[++top],a);
}
void dis()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%s\n",strrev(store[i]));
    }
}
int main()
{
    int s;
    top = -1;
    printf("Enter the size of Stack : ");
    scanf("%d",&n);
    while(1)
    {
        printf("1.Insert String\n2.Reverse Display(per string)\n3.Exit\nEnter your choice: ");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Enter a word : ");
                scanf("%s",a);
                push(a);
                break;
            case 2:
                dis();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("INVALID CHOICE!!!\n");
        }
    }
}