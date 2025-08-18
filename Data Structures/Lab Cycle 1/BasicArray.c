// #include stdio.h
#define  MAX 100
void traverse(int arr[],int n)
{
    printf("\n Array Elements:");
    for(int i = 0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
int insert(int arr[], int *size, int value, int pos)
 {
    if (*size >= MAX || pos < 0 || pos > *size) return 0;

    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
    return 1;
}
int delete(int arr[], int *size, int value) {
    int i, found = 0;
    for (i = 0; i < *size; i++) {
        if (arr[i] == value) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;

    for (int j = i; j < *size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    (*size)--;
    return 1;
}

int search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

void displayEvenPositions(int arr[], int size) {
    printf("Values at even positions (index 0, 2, 4...):\n");
    for (int i = 0; i < size; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayOddValues(int arr[], int size) {
    printf("Odd-numbered values:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void displayAlternatePositions(int arr[], int size) {
    printf("Values at alternate positions (index 0, 2, 4...):\n");
    for (int i = 0; i < size; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int arr[MAX], size = 0, choice, value, pos, result;

    printf("Enter the number of elements: ");
    scanf("%d", &size);
    if (size > MAX) {
        printf("Size exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Menu ---\n");
        printf("1. Traverse array\n");
        printf("2. Insert value\n");
        printf("3. Delete value\n");
        printf("4. Search element\n");
        printf("5. Display values at even positions\n");
        printf("6. Display odd-numbered values\n");
        printf("7. Display values at alternate positions\n");
        printf("8. Reverse array\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                traverse(arr, size);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &pos);
                if (insert(arr, &size, value, pos)) {
                    printf("Value inserted successfully.\n");
                } else {
                    printf("Insertion failed.\n");
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (delete(arr, &size, value)) {
                    printf("Value deleted successfully.\n");
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(arr, size, value);
                if (result != -1) {
                    printf("Value found at index %d.\n", result);
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 5:
                displayEvenPositions(arr, size);
                break;
            case 6:
                displayOddValues(arr, size);
                break;
            case 7:
                displayAlternatePositions(arr, size);
                break;
            case 8:
                reverse(arr, size);
                printf("Array reversed.\n");
                break;
            case 9:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 9);

    return 0;
}