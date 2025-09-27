#include<stdio.h>
int main()
{
	int a , b, r,s1,s2,s3,base ,height, width;
	float pi=3.14;
	printf("For Circle 1\nFor Triangle 2\nFor Rectangular 3\n");
	scanf("%d",&a);
	switch(a){
	case 1: {
		printf("You entered Cirlce\n");
		printf("For Perimeter 1\nFor Area 2 \n");
		scanf("%d",&b);
		switch(b){
			case 1:{
				printf("\nEnter the radius ");
				scanf("%d",&r);
				printf("Perimeter or Circumfarence of given Circle =%f",2*pi*r);
				break;
			}
			case 2:{
				printf("\nEnter the radius ");
				scanf("\n%d",&r);
				printf("\nArea of given Circle =%f",pi*r*r);
				break;
			}
			default :{
				printf("You entered invalid number or character");
				break;
			}
		}
		break;
	}
	case 2:{
		printf("You entered Triangle\n");
		printf("For Perimeter 1\nFor Area 2 \n");
		scanf("%d",&b);
		switch(b){
			case 1:{
				printf("Enter the three sides of Triangle one by one\n");
				scanf("\n%d",&s1);
				scanf("\n%d",&s2);
				scanf("\n%d",&s3);
				printf("Perimeter of given Triangle =%d ",s1+s2+s3);
				break;
			}
			case 2:{
				printf("\nEnter the the base and height of Triangle \n");
				scanf("\n%d",&base);
				scanf("\n%d",&height);
				printf("Area of given Triangle =%f",(base*height)/(2.0));
				break;
			}
			default :{
				printf("You entered invalid number or character");
				break;
			}
		}
		
		break;
	}
		case 3:{
		printf("You entered Rectangular\n");
		printf("For Perimeter 1\nFor Area 2\n");
		scanf("%d",&b);
		switch(b){
			case 1:{
				printf("Enter the width and height one by one\n");
				scanf("\n%d",&s1);
				scanf("\n%d",&s2);
				printf("Perimeter of Rectangular =%d",2*(s1+s2));
				break;
			}
			case 2:{
				printf("\nEnter the the width and height of Rectangular\n");
				scanf("\n%d",&width);
				scanf("\n%d",&height);
				printf("Area of given Rectangular =%d",(width*height));
				break;
			}
			default :{
				printf("You entered invalid number or character");
				break;
			}
		}
		
		break;
	}
	default:{
		printf("You entered invalid number or character");
		break;
	}
    } 
	return 0;
}