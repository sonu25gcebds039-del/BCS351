#include<stdio.h>
int main()
{
    int arr[100], n, i, j, t, key, mid, low , high , found = 0;
    printf("Enter the no. of elements:");
    scanf("%d", &n);
    printf("Enter elements: \n ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    printf("Sorted Array:");
    for(i=0; i<n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n Enter element to search:");
    scanf("%d", &key);
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == key)
        {
            printf("Element found at position %d \n",mid + 1);
            found = 1;
            break;

        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if(! found)
    {
        printf("Element not found:\n");
    }
    return 0;


}