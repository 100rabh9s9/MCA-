// To sort prices of items in descending order using bubblesort

#include <stdio.h>
void pricesort(float price[],int size)
{
    for(int i =0;i<size-1;i++)
    {
        for(int j =0 ;j<size-i-1;j++)
        {
            if(price[j]<price[j+1])
            {
                float temp = price[j];
                price[j]= price[j+1];
                price[j+1]= temp;
            }
        }
    }
}
int main()
{
    int size;
    printf("\n Enter No of items:");
    scanf("%d",&size);
    float price[size];
    printf("\n Enter Prices of %d items:",size);
    for(int i =0;i<size;i++)
    {
        printf("\n Price of item %d: ",i+1);
        scanf("%f",&price[i]);
    }
    //bubbleosrt
    pricesort(price,size);
    printf("\n  prices in descending order:");
    for(int i = 0;i<size;i++)
    {
        printf(" %.2f",price[i]);
    }
    printf("\n");
return 0;
}