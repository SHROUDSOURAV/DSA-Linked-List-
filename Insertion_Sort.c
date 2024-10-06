#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of Array : ");
    scanf("%d",&n);
    int a[n],i,j,temp;
    printf("Enter the elements of Array :\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted Array :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    for(i=1;i<n;i++)//unsorted sublist loop
    {
        temp = a[i];//insert element
        j = i-1;//decrementing loop (sorted sublist)
        while(j>=0 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}