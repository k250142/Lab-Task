#include<stdio.h>
int main()
{ 
    int a,b,c;
    printf("Enter the value of a = ");
    scanf("%d",&a);
    printf("\nEnter the value of b = ");
    scanf("%d",&b);
    c=a;
    a=b;
    b=c;
    printf("\nAfter swap the value of a = %d",a);
    printf("\nAfter swap the value of b = %d",b);
    return 0;
}