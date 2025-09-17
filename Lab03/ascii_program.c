#include<stdio.h>
int main()
{
    int x;
    printf("Enter the value of x = ");
    scanf("%d",&x);
    if(x > 64 && x < 97){
        printf("\nThe value of x = %d",x);
        printf("\nFor x character is %c",x);
    }
    else {
        printf("\nYou Entered Out of Range value");
    }
    return 0;
}