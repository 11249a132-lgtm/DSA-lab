/* Aim:
To write a C program to implement the Quick Sort algorithm using the divide-and-conquer technique, by selecting a pivot,
partitioning the array, and recursively sorting the subarrays to obtain a fully sorted list.*/

#include <stdio.h>

/*
    FUNCTION: swap
    PURPOSE : Swap two integer values using call-by-reference.
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    FUNCTION: partition
    PURPOSE : Rearranges the array around a pivot such that:
              - Elements smaller than pivot are on the left
              - Elements greater than pivot are on the right
              Returns the final position (index) of the pivot.
*/
int partition(int list[], int low, int high)
{
    int pivot = list[high];   // Choose last element as pivot
    int i = low - 1;          // i tracks index for smaller elements

    // Traverse array from low to high-1
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than pivot
        if (list[j] < pivot)
        {
            i++;                             // Move smaller element index forward
            swap(&list[i], &list[j]);        // Swap with current element
        }
    }

    // Place pivot in its correct sorted position
    swap(&list[i + 1], &list[high]);
    
    return i + 1;   // Return pivot index
}

/*
    FUNCTION: quickSort
    PURPOSE : Apply Quick Sort recursively using divide-and-conquer:
              1. Partition array
              2. Recursively sort left subarray
              3. Recursively sort right subarray
*/
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high); // Get pivot position

        // Recursively sort elements before and after pivot
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;

    // Read number of elements from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];   // Array declaration

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    // Call Quick Sort
    quickSort(list, 0, n - 1);

    // Display sorted array
    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}
