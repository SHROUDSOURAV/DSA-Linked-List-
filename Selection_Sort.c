#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of Array : ");
    scanf("%d",&n);
    int a[n];
    int i,j,min,temp;
    printf("Enter the Array elements :\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted Array :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    for(i=0;i<n;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[min] > a[j])
                min = j;
        }
        if(i != min)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    printf("\nSorted Array :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}