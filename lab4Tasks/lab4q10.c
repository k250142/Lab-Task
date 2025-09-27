#include<stdio.h>
int main()
{
	int age,type;
	printf("Enter Your age ");
	scanf("%d",&age);
	if(age>0 && age<12){
		printf("\nChild Ticket");
		printf("\nSelect Movie Type");
		printf("\n1. Action Movie");
		printf("\n2. Comedy Movie");
		printf("\n3. Horror Movie\n");
		scanf("%d",&type);
		switch(type){
			case 1:{
				printf("You booked Action Movie with Child Ticket");
				break;
			}
			case 2:{
				printf("You booked Comedy Movie with Child Ticket");
				break;
			}
			case 3:{
				printf("You booked Horror Movie with Child Ticket");
				break;
			}
			default:{
				printf("You select invalid movie type");
				break;
			}
		}
		
	}
	else if(age>=12 && age<=60){
		printf("\nAdult Ticket");
		printf("\nSelect Movie Type");
		printf("\n1. Action Movie");
		printf("\n2. Comedy Movie");
		printf("\n3. Horror Movie\n");
		scanf("%d",&type);
		switch(type){
			case 1:{
				printf("You booked Action Movie with Adult Ticket");
				break;
			}
			case 2:{
				printf("You booked Comedy Movie with Adult Ticket");
				break;
			}
			case 3:{
				printf("You booked Horror Movie with Adult Ticket");
				break;
			}
			default:{
				printf("You select invalid movie type");
				break;
			}
		}
	}
	else if (age>60)
	{
		printf("\nSenior Citizen Ticket");
		printf("\n1. Action Movie");
		printf("\n2. Comedy Movie");
		printf("\n3. Horror Movie\n");
		scanf("%d",&type);
		switch(type){
			case 1:{
				printf("You booked Action Movie with Senior Citizen Ticket");
				break;
			}
			case 2:{
				printf("You booked Comedy Movie with Senior Citizen Ticket");
				break;
			}
			case 3:{
				printf("You booked Horror Movie with Senior Citizen Ticket");
				break;
			}
			default:{
				printf("You select invalid movie type");
				break;
			}
		}
	}
	else{
		printf("You Entered Invalid age");
	}
	return 0;
}