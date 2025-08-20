 //Program to perform Search on an array of Numbers
 #include <stdio.h>
 int linearsearch(int arr[],int size,int value)
 {
     for(int i = 0;i<size;i++)
     {
         if(arr[i]==value)
         {
             return i;
         }
     }
     return -1;
 }
 int main()
 {
     int arr[100],size,result,value;
     printf("\n Enter Number of Elements:");
     scanf("%d",&size);
     printf("\n Enter Array Elements: ");
        for(int i= 0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
     printf("\n Enter Element to search:");
     scanf("%d",&value);
     result = linearsearch(arr,size,value);
     if(result !=-1)
     {
         printf("\n Element %d is found at %d",value,result+1);
     }
     else
     {
         printf("\n Element Not Found");
     }
     return 0;
}