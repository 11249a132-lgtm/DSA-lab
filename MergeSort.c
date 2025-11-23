/* Aim:
To write a C program to implement the Merge Sort algorithm using a divide-and-conquer approach, where the array is recursively divided into two halves,
sorted individually, and then merged to produce a fully sorted array.*/

#include <stdio.h>

/*
    FUNCTION: merge
    PURPOSE : Merge two sorted subarrays into one sorted array.
              The two subarrays are:
              - arr[left … mid]
              - arr[mid+1 … right]
*/
void merge(int arr[], int left, int mid, int right)
{
    int i = left;       // Starting index of left subarray
    int j = mid + 1;    // Starting index of right subarray
    int k = 0;          // Index for temporary array

    int temp[right - left + 1];  // Temporary array to store merged output

    // Merge elements in sorted order
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right subarray
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy sorted temp array back to original array
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

/*
    FUNCTION: mergeSort
    PURPOSE : Recursively divide the array into two halves,
              sort them and merge them.
*/
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);      // Sort left half
        mergeSort(arr, mid + 1, right); // Sort right half

        merge(arr, left, mid, right);   // Merge two sorted halves
    }
}

int main()
{
    int n;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Apply Merge Sort
    mergeSort(arr, 0, n - 1);

    // Output sorted array
    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
