#include <stdio.h>

void updateCharacter(char arr[], int size)
{
    int pos;
    char newChar;

    printf("\nEnter position to update (0 to %d): ", size - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= size)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter new character: ");
    scanf(" %c", &newChar);

    arr[pos] = newChar;
    printf("Updated character at position %d to '%c'.\n", pos, newChar);
    
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
        printf("Character [%d]: ", i);
        scanf(" %c", &arr[i]);
    }
        updateCharacter(arr, size);
    return 0;
}