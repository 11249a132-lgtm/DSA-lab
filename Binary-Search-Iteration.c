/* Aim:
To write a C program that performs Binary Search on a sorted array to efficiently find the position of a target element by repeatedly dividing the search interval into two halves.*/

#include <stdio.h>
int main()
{
    int size, targetElement, start, mid, end;

    // Ask user for array size
    printf("Enter the size of array: ");
    scanf("%d", &size);

    // Declare array of required size
    int searchSpace[size];

    // Read array elements from user
    // NOTE: For binary search, array must be in **sorted order**
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d of %d: ", i, size - 1);
        scanf("%d", &searchSpace[i]);
    }

    // Read element to search
    printf("Enter the element to search: ");
    scanf("%d", &targetElement);

    // Initialize start and end pointers
    start = 0;
    end = size - 1;

    // Binary Search Loop
    while (start <= end)
    {
        // Find middle index
        mid = (start + end) / 2;

        // If middle element is equal to required element
        if (searchSpace[mid] == targetElement)
        {
            printf("Element found at index %d (i.e., position %d)", mid, mid + 1);
            return 0;   // End program after successful search
        }
        // If middle element is less than target → Search in right half
        else if (searchSpace[mid] < targetElement)
        {
            start = mid + 1;
        }
        // If middle element is greater than target → Search in left half
        else
        {
            end = mid - 1;
        }
    }

    // If loop ends → Element not found
    printf("Element doesn't exist in the given search set");

    return 0;
}
