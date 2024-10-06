#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of Array : ");
    scanf("%d",&n);
    int a[n],i,j,temp;
    printf("Enter the Array elements : \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted Array :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j] > a[j+1])//compare before swapping
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("\nSorted Array :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}