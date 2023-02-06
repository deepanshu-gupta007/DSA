//selection sort
#include<stdio.h>
#define max 100
void selection_sort(int arr[], int n)
{
    int i, j, min, pos, temp;
    for(i=0; i<n-1; i++)
    {
        min=arr[i], pos=i;
        for(j=i+1; j<n; j++)
            if (arr[j]<min)
                min=arr[j], pos=j;
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
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
    selection_sort(arr, n);
    printf("After sorting:\n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    return 0;
}