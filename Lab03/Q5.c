#include <stdio.h>
int main()
{
    float Salary, HRA, DA, GrossSalary;
    printf("Enter your Salary = ");
    scanf("%f", &Salary);
    HRA = Salary * 0.05;
    DA = Salary * 0.1;
    GrossSalary = Salary + HRA + DA;
    printf("\nYour Gross Salary is %.2f", GrossSalary);
    return 0;
}