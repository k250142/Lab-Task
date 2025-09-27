#include <stdio.h>
#include <math.h>
int main()
{
    int l, y, t, r;   // principal, years, type, rate
    float si, ci, amount;
    printf("Enter Your Loan Amount: "); 
    scanf("%d", &l);
    printf("Enter years: "); 
    scanf("%d", &y);
    printf("Enter interest rate (percentage) without percentage sign: "); 
    scanf("%d", &r);
    printf("Enter Loan type \n1. Simple Interest \n2. Compound Interest\n");
    scanf("%d", &t);
    if(t == 1){
        si = (l * y * r) / 100.0;
        printf("\nSimple Interest = %.2f", si);
        printf("\nTotal amount to be paid %.2f",l+si);
    }
    else if(t == 2){
        amount = l * pow((1 + r / 100.0), y);
        ci = amount - l;
        printf("\nCompound Interest = %.2f", ci);
        printf("\nTotal amount to be paid %.2f",l+ci);
    }
    else{
        printf("\nInvalid loan type selected!");
    }
    return 0;
}