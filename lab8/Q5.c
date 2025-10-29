#include <stdio.h>

int main() {
    int marks[5][4];
    int i, j;
    float avg[5];
    int high[4] = {0};
    printf("Enter marks of 5 students in 4 subjects:\n");
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
        	printf("Enter Marks Student No. %d Subject No. %d  ==",i+1, j+1);
            scanf("%d", &marks[i][j]);
        }
    }
    for(i=0;i<5;i++){
        int sum = 0;
        for(j=0;j<4;j++){
            sum += marks[i][j];
            if(marks[i][j] > high[j]){
            	high[j] = marks[i][j];
			}     
        }
        avg[i] = sum / 4.0;
    }
    printf("Average marks of each student:\n");
    for(i=0;i<5;i++){
    	printf("Average marks of student: %d", i+1);
        printf("%.2f \n", avg[i]);
    }
    printf("\nHighest marks in each subject:\n");
    for(j=0;j<4;j++){
    	printf("Higest marks of Subject: %d", j+1);
        printf("%d \n", high[j]);
    }
    return 0;
}
