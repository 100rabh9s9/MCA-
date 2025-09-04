 //Create an array of integers and display the array using pointers in C
 #include <stdio.h>
 #include <stdlib.h>
 int main()
 {
     int size;
     int *ptr;
     printf("\n Enter Size of Array: ");
     scanf("%d",&size);
     
     ptr = (int*)malloc(size*sizeof(int)); //Allocate memory for n integers
      // Check if malloc failed
     if(ptr == NULL)
     {
         printf("Oops Memory Allocation Failed!");
     }
     else
     {
        printf("\n Enter %d Array Elements:",size);
        for(int i = 0 ; i < size ; i++)
        {
            scanf("%d",ptr+i);
        }
     }
     printf("\n");
     // Output elements using pointer arithmetic
     printf("\n Array Elements are: ");
     for(int i = 0 ; i < size ; i++)
     {
        printf("%d",*(ptr+i));
        printf(" ");
     }
     
    free(ptr);  // Free the allocated memory
    return 0;
 }
