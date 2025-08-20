// Program to sort list of characters in alphabetical order using bubblesort
#include <stdio.h>
void bubblesort(char arr[],int size) //function Defintion
{
    for(int i =0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                char temp = arr[j]; //temp is a swqp elemet
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
}
int main()
{
    int size;
    printf("\n Enter Size of array:");
    scanf("%d",&size); // Variable Length Array (VLA)
    char arr[size];
    printf("\n Enter Array Elements: ");
    for(int i=0;i<size;i++)
    {
        scanf(" %c",&arr[i]); //Space given to address newline issue 
    }
    
    bubblesort(arr,size);//Function call 
    printf("\n Sorted Array:");
    for(int i =0;i<size;i++)
    {
        printf(" %c",arr[i]);
    }
    printf("\n");
return 0;
}