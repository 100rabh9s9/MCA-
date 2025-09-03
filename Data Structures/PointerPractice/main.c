//Create a character pointer and read and display the value using pointer variable.
#include <stdio.h>
int main()
{
    char *ptr; //Character Pointer
    char ch;
    printf("\n Enter a Character:");
    scanf("%c",&ch);
    ptr = &ch;
    printf("\n The Character Entered is: %c ",*ptr);
    printf("The address of the character is: %p\n", (void *)ptr); // Print the address stored in the pointer 'ptr'
    //The %p format specifier in printf is specifically used to print pointers (memory addresses).
return 0;
}