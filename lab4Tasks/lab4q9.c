#include<stdio.h>
int main()
{
	int a,b;
	printf("Kindly Select the department\n");
	printf("1. Computer Science (CS)\n2. Electrical Engineering (EE)\n3. Business Administration (BBA)\n");
	scanf("%d",&a);
	switch (a){
		case 1:{
			printf("Kindly Select the Course\n1. Data Structure\n2. Algorithm\n3. Operating System\n");
			scanf("%d",b);
			switch (b){
				case 1:{
					printf("You Selected Data Structure");
					break;
				}
				case 2:{
					printf("You Selected Algorithm");
					break;
				}
				case 3:{
					printf("You Selected Operating System");
					break;
				}
				default : {
					printf("You entered invalid Course of CS");
					break;
				}
			}
			break;
		}
		case 2:{
			printf("Kindly Select the Course\n1. Circuit Analysics\n2. Electromagnetics\n3. Power System\n");
			scanf("%d",&b);
			switch (b){
				case 1:{
					printf("You Selected Circuit Analysics");
					break;
				}
				case 2:{
					printf("You Selected Electromagnetics");
					break;
				}
				case 3:{
					printf("You Selected Power System");
					break;
				}
				default : {
					printf("You entered invalid Course of EE");
					break;
				}
			}
			break;
		}
		case 3:{
			printf("Kindly Select the Course\n1. Principal of Management\n2. Marketing Fundamentals\n3. Financial Accounting\n");
			scanf("%d",&b);
			switch (b){
				case 1:{
					printf("You Selected Principal of Management");
					break;
				}
				case 2:{
					printf("You Selected Marketing Fundamentals");
					break;
				}
				case 3:{
					printf("You Selected Financial Accounting");
					break;
				}
				default : {
					printf("You entered invalid Course of BBA");
					break;
				}
			}
			break;
		}
		default : {
					printf("You entered invalid Department");
					break;
				}
	}
	return 0;
}