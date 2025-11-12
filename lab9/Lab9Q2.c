#include<stdio.h>

void cal( int *s){
	int tp=0;
	for(int i =0; i<5; i++){
		
		if ( *(s+i) <30000){
		printf("bonus salary of Employee %d is  %.2f  \n", i+1, (*(s+i) * 0.2));
		tp+=(*(s+i) * 0.2);
	    }
	    else{
	    printf("bonus salary of Employee %d is  %.2f  \n", i+1, (*(s+i) * 0.1));
	    tp+=(*(s+i) * 0.1);
		}
	}
	printf("Total payout is %d", tp);
	return;
}
  
int main(){
	int a[5];
	step:
	for(int i=0; i<5; i++){
		printf("Enter the salary of Employee %d:  ", i+1);
		scanf("%d", a+i);
		if(*(a+i)<0){
			printf("Entered Invalid Salary Try again\n");
			goto step;
		}
	}
	cal(a);
	
	
	
	return 0;
}