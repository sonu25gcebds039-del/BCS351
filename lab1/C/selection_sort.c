#include <stdio.h> 
 
void selectionSort(int arr[], int n) { 
    int i, j, min_idx, temp; 
 
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) { 
 
 

            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        } 

        if (min_idx != i) { 
            temp = arr[min_idx]; 
            arr[min_idx] = arr[i]; 
            arr[i] = temp; 
        } 
    } 
} 
 
void printArray(int arr[], int size) { 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int main() { 
    int arr[] = {29, 10, 14, 37, 13}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
 
    printf("Original array:\n"); 
    printArray(arr, n); 
 
    selectionSort(arr, n); 
 
    printf("Sorted array:\n"); 
    printArray(arr, n); 
 
    return 0; 
} 
