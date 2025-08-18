/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int searchElement(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int main() 
{
    int arr[100], size,key,index ;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 0 || size > 100)
    {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("\n Enter Value to search: ");
    scanf("%d",&key);
    index=searchElement(arr,size,key);
    if (index != -1)
    {
        printf("Element %d found at index %d.\n", key, index+1);
    }
    else
    {
        printf("Element %d not found in the array.\n", key);
    }
return 0;
}
