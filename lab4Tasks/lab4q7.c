#include<stdio.h>
#include<string.h>
int main()
{
	char u[20];
	char p[20];
	printf("Enter the Username ");
	scanf("%s",u);
	printf("\nEnter the Password ");
	scanf("%s",p);
	if(strcmp(u,"admin")==0) {
		if(strcmp(p,"1234")==0){
			printf("Login successful");
		}
		else
		{
			printf("Error (password)");
		}
	}
	else
	{
		printf("Error (username)");
	}
	return 0;
}