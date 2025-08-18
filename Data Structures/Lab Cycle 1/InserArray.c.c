#include <stdio.h>

int insertValue(int arr[], int size, int value, int position) {
    if (size >= 100 || position < 0 || position > size) {
        return size; // insertion failed, return unchanged size
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    size++;
    return size;
}

int main() {
    int arr[100], size, value, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 0 || size > 100) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask user for the value and position
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    printf("Enter the position to insert at (0 to %d): ", size);
    scanf("%d", &position);

    int newSize = insertValue(arr, size, value, position);

    // Check if insertion was successful
    if (newSize == size) {
        printf("Insertion failed. Invalid position or array is full.\n");
    } else {
        printf("Array after insertion:\n");
        for (int i = 0; i < newSize; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
