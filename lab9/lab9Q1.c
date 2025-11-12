#include <stdio.h>
void input(int *p , int n){
	int i;
	for(i=0; i<n ; i++){
		scanf("%d", p + i);
	}
	return;
}
float avg(int *p, int n) {
    float sum=0.0;
    for(int i=0; i<n; i++) {
        sum=sum + *(p + i);
    }
    
    return (float)sum/n;
}
int busiestday(int *p , int n){
	int i, b=0 , c=0;
	for(i=0; i<n ; i++){
		if(*(p+i)>b){
			b= *(p+i);
			c=i+1;
		}
	}
	return c;
}
 int sday( int *p , int n){
	int i, b=*p , c=1;
	for(i=1; i<n ; i++){
		if(*(p+i)<b){
			b= *(p+i);
			c=i+1;
		}
	}
	return c;
}

int main() {
    int d=7, p[7], i=0;

    input(p , d);
    float avge = avg(p, d);
    int b=busiestday(p , d);
    int s=sday(p , d);
    printf("Avg %.2f\n",avge);
    printf("B day %d  (Patients %d)\n",b, *(p+b-1));
    printf("S day %d  (Patients %d)", s, *(p+s-1));
   
    return 0;
}

