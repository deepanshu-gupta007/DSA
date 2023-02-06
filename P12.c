//bubble sort
#include<stdio.h>
#define max 100
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n, i, arr[max];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    printf("After sorting:\n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    return 0;
}