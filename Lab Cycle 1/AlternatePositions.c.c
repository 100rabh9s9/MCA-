/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void alternatepositons(int arr[],int size)
{
    printf("\n Elements in alternate Positions: ");
    for(int i=0;i<size;i+=2) //step by 2 for alternate positons
    {
        printf("%d",arr[i]);
        printf("\t");
    }
     
}

int main() 
{
    int arr[100], size;

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
    alternatepositons(arr,size);//function Call 
return 0;
}