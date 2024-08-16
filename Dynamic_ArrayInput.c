#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;//array input variable
    int n;//array size variable
    int i;//loop variable/indexing

    printf("Enter the size of Array : ");
    scanf("%d",&n);

    ptr = (int *)malloc(n*(sizeof(int)));//dynamically allocate memory for n number of elements in array
    if(ptr == NULL)
    {
        printf("Memory Allocation Failed!!!\n");
        exit(0);
    }
    printf("Memory Allocation Sucessful\n\n");
    printf("Enter array elements :\n");
    for(i=0;i<n;i++)
        scanf("%d",&ptr[i]);//inputting array elements using scanf() fucntion


    printf("Displaying Array :\n");
    for(i=0;i<n;i++)//displaying array elements using for loop
        printf("%d\n",ptr[i]);
    return 0;
}