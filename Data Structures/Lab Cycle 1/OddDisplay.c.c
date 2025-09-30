#include <stdio.h>
void OddDisplay(int arr[],int size) //Odd Position Display 
{
    printf("\n Odd Valued Elements: ");
    for(int i=0;i<size;i++) 
    {
        if(arr[i] % 2 != 0) //Check if odd 
        {
            printf("%d",arr[i]);
            printf("\t");
        }
    }     
}
int main() 
{
    int arr[100], size; //Static Allocation 
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 0 || size > 100)  //Checking for invalid conditions 
    {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
    OddDisplay(arr,size); //function Call 
return 0;
}
