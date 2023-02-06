//insertion sort
#include<stdio.h>
#define max 100
void insertion_sort(int arr[], int n)
{
    int i, j, ele;
    for(i=0; i<n; i++)
    {
        ele=arr[i], j=i-1;
        while(j>=0 && ele<arr[j])
            arr[j+1]=arr[j--];
        arr[j+1]=ele;
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
    insertion_sort(arr, n);
    printf("After sorting:\n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    return 0;
}