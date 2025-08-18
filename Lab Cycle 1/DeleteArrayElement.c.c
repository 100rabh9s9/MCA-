#include <stdio.h>

// Function that deletes an element and returns the new size
int deleteElement(int arr[], int size, int position)
{
    if (position < 0 || position >= size)
    {
        printf("Invalid Position\n");
        return size; // return unchanged size
    }

    // Shift elements left to overwrite the one at 'position'
    for (int i = position; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--; // Decrease size

    printf("\nValue at position %d deleted.\n", position);
    printf("Traversed Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return size;
}

int main()
{
    int arr[100], size, position;

    printf("\nEnter size of array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position of element to be deleted (0 to %d): ", size - 1);
    scanf("%d", &position);

    // Call delete function and update size
    size = deleteElement(arr, size, position);

    return 0;
}
