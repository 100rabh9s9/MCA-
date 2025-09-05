//Create an array of characters and display the array using pointers.f
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    char *ptr;
    printf("\n Enter Size of Array : ");
    scanf("%d",&size);
    getchar();
    
    ptr = (char*)malloc((size+1)*sizeof(char));
    
    if(ptr == NULL)
    {
        printf("Oops! Memory Allocation Failed");
    }
    printf("\n Enter %d Characters:",size);
    for(int i = 0 ; i < size ; i ++ )
    {
        scanf(" %c",ptr+i);
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
    
    free(ptr);
    return 0;
  
}