#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int daysLeft;
} Event;

void task2Menu();
void countdownRecursive(int days);
void displayEventCountdowns(Event events[], int count);

int main() {
    task2Menu();
    return 0;
}

void task2Menu() {
    Event events[50];
    int count = 0;
    int choice;

    while(1) {
        printf("\n--- TASK 2: EVENT COUNTDOWN SYSTEM ---\n");
        printf("1. Add Event\n");
        printf("2. Display Countdowns\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: {
                if(count >= 50) {
                    printf("Maximum events reached\n");
                    break;
                }
                printf("Enter event name: ");
                fgets(events[count].name, sizeof(events[count].name), stdin);
                events[count].name[strcspn(events[count].name, "\n")] = 0;

                printf("Enter days left: ");
                scanf("%d", &events[count].daysLeft);
                getchar();

                count++;
                printf("Event added successfully\n");
                break;
            }
            case 2: displayEventCountdowns(events, count); break;
            case 3: return;
            default: printf("Invalid choice\n");
        }
    }
}

void countdownRecursive(int days) {
    if(days == 0) {
        printf("Event today!\n");
        return;
    }
    printf("%d ", days);
    countdownRecursive(days - 1);
}

void displayEventCountdowns(Event events[], int count) {
    if(count == 0) {
        printf("No events to display\n");
        return;
    }
    printf("\n=== EVENT COUNTDOWNS ===\n");
    for(int i = 0; i < count; i++) {
        printf("%s: ", events[i].name);
        countdownRecursive(events[i].daysLeft);
        printf("\n");
    }
}
