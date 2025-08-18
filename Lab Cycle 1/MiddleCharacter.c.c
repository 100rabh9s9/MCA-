#include <stdio.h>

void MiddleCharacter(char arr[], int size)
{
    int mid = size / 2;

    printf("\nMiddle character: ");
    if (size % 2 == 0) 
    {
        printf("'%c' and '%c'\n", arr[mid - 1], arr[mid]);
    } 
    else 
    {
        printf("'%c'\n", arr[mid]);
    }
}
int main()
{
    char arr[100];
    int size;
    printf("Enter the size of the character array: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) 
    {
        printf("Invalid size.\n");
        return 1;
    }
    printf("Enter %d characters:\n", size);
    for (int i = 0; i < size; i++) 
    {
        printf("Character: ");
        scanf(" %c", &arr[i]);
    }
        MiddleCharacter(arr, size);
    return 0;
}