#include<stdio.h>
#include<stdlib.h>
struct queue 
{
    int data;
    struct queue *next;
};
struct queue *new_node,*traverse;//global struct queue pointers
struct queue *create_node()
{
    struct queue *new_node;
    new_node = (struct queue *)malloc(sizeof(struct queue));//allocating memory for new_node insertion
    printf("Enter the data to insert(queue): ");
    scanf("%d",&new_node->data);
    return new_node;
}
int main()
{
    int a;//switch variable
    char ch;//loop condition variable
    struct queue *start = NULL;
    do
    {
        switch(a)
        {

        }
        printf("Do you want to Continue(Y/N): ");
        scanf(" %c",&ch);
    } while (ch == 'Y' || ch == 'y');
    return 0;
}