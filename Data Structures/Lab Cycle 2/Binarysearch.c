#include <stdio.h>
#include <ctype.h>
//Program to Search alphabets using BinarySearch 
int binarysearch(char arr[], int low, int high, char target) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (tolower(arr[mid]) == tolower(target)) {
            return mid;
        }
        if (tolower(arr[mid]) > tolower(target)) {
            return binarysearch(arr, low, mid - 1, target);
        } else {
            return binarysearch(arr, mid + 1, high, target);
        }
    }
    return -1; // If not found
}

int main() {
    char Alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int size = sizeof(Alphabets) / sizeof(Alphabets[0]);
    char target;

    printf("\nEnter character to search: ");
    scanf(" %c", &target); // Note the space before %c to handle the newline

    int result = binarysearch(Alphabets, 0, size - 1, target);

    if (result != -1) {
        printf("\nCharacter '%c' found at index %d\n", target, result);
    } else {
        printf("\nCharacter '%c' is not found\n", target);
    }

    return 0;
}

