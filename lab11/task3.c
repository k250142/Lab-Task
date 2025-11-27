#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    int daysPresent;
} Employee;

void task3Menu();
void addEmployee(Employee employees[], int *count);
void displayEmployees(Employee employees[], int count);
int calculateTotalAttendanceRecursive(Employee employees[], int index, int count);
void findLowAttendance(Employee employees[], int count, int minDays);

int main() {
    task3Menu();
    return 0;
}

void task3Menu() {
    Employee employees[100];
    int count = 0;
    int choice;

    while(1) {
        printf("\n--- TASK 3: EMPLOYEE ATTENDANCE SYSTEM ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Calculate Total Attendance\n");
        printf("4. Find Low Attendance\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: addEmployee(employees, &count); break;
            case 2: displayEmployees(employees, count); break;
            case 3: {
                int total = calculateTotalAttendanceRecursive(employees, 0, count);
                printf("Total attendance for all employees: %d days\n", total);
                break;
            }
            case 4: {
                int minDays;
                printf("Enter minimum required days: ");
                scanf("%d", &minDays);
                getchar();
                findLowAttendance(employees, count, minDays);
                break;
            }
            case 5: return;
            default: printf("Invalid choice\n");
        }
    }
}

void addEmployee(Employee employees[], int *count) {
    if(*count >= 100) {
        printf("Maximum employees reached\n");
        return;
    }
    printf("Enter employee name: ");
    fgets(employees[*count].name, sizeof(employees[*count].name), stdin);
    employees[*count].name[strcspn(employees[*count].name, "\n")] = 0;

    printf("Enter employee ID: ");
    scanf("%d", &employees[*count].id);

    printf("Enter days present: ");
    scanf("%d", &employees[*count].daysPresent);
    getchar();

    (*count)++;
    printf("Employee added successfully\n");
}

void displayEmployees(Employee employees[], int count) {
    if(count == 0) {
        printf("No employees to display\n");
        return;
    }
    printf("\n=== ALL EMPLOYEES ===\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s | ID: %d | Days Present: %d\n",
               i+1, employees[i].name, employees[i].id, employees[i].daysPresent);
    }
}

int calculateTotalAttendanceRecursive(Employee employees[], int index, int count) {
    if(index >= count) return 0;
    return employees[index].daysPresent + calculateTotalAttendanceRecursive(employees, index + 1, count);
}

void findLowAttendance(Employee employees[], int count, int minDays) {
    printf("\n=== EMPLOYEES WITH ATTENDANCE < %d DAYS ===\n", minDays);
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(employees[i].daysPresent < minDays) {
            printf("%s | ID: %d | Days Present: %d\n",
                   employees[i].name, employees[i].id, employees[i].daysPresent);
            found = 1;
        }
    }
    if(!found) printf("No employees found\n");
}
