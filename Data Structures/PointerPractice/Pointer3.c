//Create an array of characters and display the array using pointers.f
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    char *ptr;
    printf("\n Enter Size of Array : ");
    scanf("%d",&size);
    getchar();  // To consume the newline character left in the input buffer after scanf
    
    ptr = (char*)malloc((size+1)*sizeof(char));  // +1 is for the null terminator '\0' to make it a valid C string
    
    if(ptr == NULL)
    {
        printf("Oops! Memory Allocation Failed");
    }
    printf("\n Enter %d Characters:",size);
    for(int i = 0 ; i < size ; i ++ )
    {
        scanf(" %c",ptr+i); // The space before %c ensures it skips any whitespace characters
        //*(ptr + i) = getchar();
    }
    
    *(ptr+size) ='\0';
    
    printf("\n The Characters are: ");
    for(int i = 0 ; i < size ; i ++ )
    {
        printf("%c",*(ptr+i));
        printf(" ");
    }
    
    printf("\nAs a string: %s\n", ptr);
    
    free(ptr);  // Free the dynamically allocated memory
    return 0;
  
}
