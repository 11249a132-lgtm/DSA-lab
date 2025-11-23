/* Aim:
To write a C program that performs Linear Search using recursion to find a given element in a dataset by repeatedly checking each array element until the element is found or the end of the array is reached. */

#include<stdio.h>
#include<stdbool.h>

/*
    Recursive Linear Search Function
    --------------------------------
    dataSet[]       -> Array of elements
    size            -> Total number of elements
    elementToFind   -> Value to search
    index           -> Current index being checked
*/
int LinearSearch(int dataSet[], int size, int elementToFind, int index)
{
    // Base case: if index goes out of range, element not found
    if (index >= size)
    {
        return -1;
    }

    // If the element at the current index matches the target
    if (dataSet[index] == elementToFind)
    {
        return index;  // Return the position
    }

    // Recursive call: check the next index
    return LinearSearch(dataSet, size, elementToFind, index + 1);
}

int main()
{
    int size, elementToFind, i;

    // Input size of dataset
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d", &size);

    // Declare array of given size
    int searchSpace[size];

    // Read dataset values
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i + 1, size);
        scanf("%d", &searchSpace[i]);
    }

    // Display the dataset
    printf("Given Dataset for Linear Search is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }

    // Input element to search
    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);

    // Call recursive linear search starting from index 0
    int foundAt = LinearSearch(searchSpace, size, elementToFind, 0);

    // Display result
    if (foundAt >= 0)
        printf("Required element %d is found in the dataset at position %d or index %d",
               elementToFind, foundAt + 1, foundAt);
    else
        printf("Required element %d is NOT found in the dataset!!!", elementToFind);

    return 0;
}
