// AIM: To write a C program that performs Linear Search on a user-given dataset to find the position of a specified element.

#include <stdio.h>

int main()
{
    int size, elementToFind, i;

    // Asking the user to enter the number of elements in the dataset
    printf("Enter the size of Data Set for Linear Search: ");
    scanf("%d", &size);

    // Declaring an array of given size
    int searchSpace[size];

    // Reading elements into the array
    for(i = 0; i <= size-1; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i+1, size);
        scanf("%d", &searchSpace[i]);
    }

    // Displaying the dataset
    printf("Given Dataset for Linear Search is: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }

    // Taking the element to find
    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);

    i = 0; // Start from the first index

    // Linear search logic
    while(i < size)
    {
        // If element matches, print position and exit
        if(searchSpace[i] == elementToFind)
        {
            printf("Required element %d is FOUND in the dataset at position %d or index %d",
                   elementToFind, i+1, i);
            return 0; // Stop program as element is found
        }
        i++; // Move to next index
    }

    // If loop completes, element was not found
    printf("Required element %d is NOT found in the dataset!!!", elementToFind);
}
