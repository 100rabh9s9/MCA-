#include<stdio.h>

int main() {
  
  int num, *p; //declaration
  p=&num; //assigning pointer to integer variable
  printf("Enter a number: ");
  scanf("%d", p);
  
  printf("The number is %d",*p);
  return 0;
}
