 #include <stdio.h>

#define MAX_SIZE 100

void traverseArray(int arr[], int size) {
    printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertValue(int arr[], int *size, int value, int position) {
    if(*size >= MAX_SIZE || position < 0 || position > *size) {
        return 0; // insertion failed
    }

    for(int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*size)++;
    return 1; // insertion successful
}

int deleteValue(int arr[], int *size, int position) {
    if(*size == 0 || position < 0 || position >= *size) {
        return 0; // deletion failed
    }

    for(int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    return 1; // deletion successful
}

int searchElement(int arr[], int size, int value) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            return i; // return index of the found element
        }
    }
    return -1; // not found
}

void displayEvenPositions(int arr[], int size) {
    printf("Values at even positions (0-based index): ");
    for(int i = 0; i < size; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayOddNumbers(int arr[], int size) {
    printf("Odd numbers in the array: ");
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void displayAlternatePositions(int arr[], int size) {
    printf("Values at alternate positions: ");
    for(int i = 0; i < size; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("Array has been reversed.\n");
}

int main() {
    int arr[MAX_SIZE],size;
    int choice, value, position, result;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    while(1) {
        printf("\nMenu:\n");
        printf("1. Traverse Array\n");
        printf("2. Insert Value\n");
        printf("3. Delete Value\n");
        printf("4. Search Element\n");
        printf("5. Display Even Positions\n");
        printf("6. Display Odd Numbers\n");
        printf("7. Display Alternate Positions\n");
        printf("8. Reverse Array\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                traverseArray(arr, size);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                result = insertValue(arr, &size, value, position);
                if(result)
                    printf("Value inserted.\n");
                else
                    printf("Insertion failed. Invalid position or array full.\n");
                break;
            case 3:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                result = deleteValue(arr, &size, position);
                if(result)
                    printf("Value deleted.\n");
                else
                    printf("Deletion failed. Invalid position.\n");
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = searchElement(arr, size, value);
                if(result != -1)
                    printf("Element found at index %d.\n", result);
                else
                    printf("Element not found.\n");
                break;
            case 5:
                displayEvenPositions(arr, size);
                break;
            case 6:
                displayOddNumbers(arr, size);
                break;
            case 7:
                displayAlternatePositions(arr, size);
                break;
            case 8:
                reverseArray(arr, size);
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
