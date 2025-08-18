#include <stdio.h>

void ArrayReverse(int arr[],int size)
{
    for(int i=0;i< size/2;i++)
    {
        int temp; //Temporary Variable to swap 
        {
            temp = arr[i];
            arr[i]= arr[size-i-1];
            arr[size-i-1] = temp;
        }
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
    ArrayReverse(arr,size); //function Call 
    printf("\n Array Reversed:");//print reversed array 
    
    for(int i =0;i< size;i++)
    {
        printf("%d",arr[i]);
        printf("  "); // Proper Spacing
    }
return 0;
}