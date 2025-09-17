#include<stdio.h>
int main()
{
    int eng,math,comp,total;
    float avg;
    printf("Enter marks of English = ");
    scanf("%d",&eng);
    printf("\nEnter marks of Math = ");
    scanf("%d",&math);
    printf("\nEnter marks of Computer = ");
    scanf("%d",&comp);
    total=eng+math+comp;
    avg=(total/300.0)*100.0;
    printf("\nTotal marks = %d",total);
    printf("\nAverage = %.2f",avg);
    return 0;
}