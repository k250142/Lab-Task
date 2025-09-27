#include<stdio.h>
int main()
{
	int a;
	printf("Enter Fast Food == 1\nEnter Drink == 2\n");
	scanf("%d",&a);
	if(a==1){
		printf("Burger\nPizza\nSandwich");
	}
	else if (a==2)
	{
		printf("CoCa Cola\nPespsi\nSprite");
	}
	else 
	{
		printf("You entered invalid number or character");
	}
	return 0;
}