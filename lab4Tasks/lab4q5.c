#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,x1,x2 ,d ,y;
	printf("Quadratic Equation general Form ax^2+bx+c=0\n");
	printf("enter the vale of a in Quadratic Equation ");
	scanf("%d",&a);
	printf("\nenter the vale of b in Quadratic Equation ");
	scanf("%d",&b);
	printf("\nenter the vale of c in Quadratic Equation ");
	scanf("%d",&c);
	printf("\nYou Enter This Quadratic Equation %dx^2+%dx+%d=0 ",a,b,c);
	y=(b*b)-(4*a*c);
	d=sqrt(y);
	x1=(-b+d)/(2*a);
	x2=(-b-d)/(2*a);
	if (y==0)
	{
		printf("\nSame Solution ");
		printf("\nx1 is %d",x1);
	    printf("\nx2 is %d",x2);
    }
	else if (y<0)
	{
		printf("\n2 complex or Imaginary Solution");
		printf("\nFor complex solution value value will be in complex quadrant");
	}
	else 
	{
		printf("\n2 Real Solutions");
		printf("\nx1 is %d",x1);
	    printf("\nx2 is %d",x2);
	}
	return 0; 
}