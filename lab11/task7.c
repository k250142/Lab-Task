#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char sign[15];
    char luckyColor[20];
    int luckyNumber;
    char advice[100];
} ZodiacForecast;

typedef struct {
    char name[50];
    char birthdate[15];
    char zodiacSign[15];
    ZodiacForecast forecast;
} User;

void task7Menu();
void addUser(User users[], int *count);
char* getZodiacSign(char *birthdate);
void displayUserHoroscope(User users[], int count, int userIndex);
void updateZodiacForecast(User users[], int count, char *zodiacSign);
void displayAllUsers(User users[], int count);

int main() {
    task7Menu();
    return 0;
}

void task7Menu() {
    User users[100];
    int count = 0;
    int choice;

    while(1) {
        printf("\n--- TASK 7: ASTROLOGY APP SYSTEM ---\n");
        printf("1. Add User\n");
        printf("2. Display All Users\n");
        printf("3. Display User Horoscope\n");
        printf("4. Update Zodiac Forecast\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: addUser(users, &count); break;
            case 2: displayAllUsers(users, count); break;
            case 3: {
                if(count == 0) {
                    printf("No users available\n");
                } else {
                    displayUserHoroscope(users, count, -1);
                }
                break;
            }
            case 4: {
                char zodiac[15];
                printf("Enter zodiac sign to update: ");
                fgets(zodiac, sizeof(zodiac), stdin);
                zodiac[strcspn(zodiac, "\n")] = 0;
                updateZodiacForecast(users, count, zodiac);
                break;
            }
            case 5: return;
            default: printf("Invalid choice\n");
        }
    }
}

void addUser(User users[], int *count) {
    if(*count >= 100) {
        printf("Maximum users reached\n");
        return;
    }
    printf("Enter user name: ");
    fgets(users[*count].name, sizeof(users[*count].name), stdin);
    users[*count].name[strcspn(users[*count].name, "\n")] = 0;

    printf("Enter birthdate (DD/MM/YYYY): ");
    fgets(users[*count].birthdate, sizeof(users[*count].birthdate), stdin);
    users[*count].birthdate[strcspn(users[*count].birthdate, "\n")] = 0;

    char *sign = getZodiacSign(users[*count].birthdate);
    strcpy(users[*count].zodiacSign, sign);

    printf("Enter lucky color for %s: ", sign);
    fgets(users[*count].forecast.luckyColor, sizeof(users[*count].forecast.luckyColor), stdin);
    users[*count].forecast.luckyColor[strcspn(users[*count].forecast.luckyColor, "\n")] = 0;

    printf("Enter lucky number: ");
    scanf("%d", &users[*count].forecast.luckyNumber);
    getchar();

    printf("Enter advice: ");
    fgets(users[*count].forecast.advice, sizeof(users[*count].forecast.advice), stdin);
    users[*count].forecast.advice[strcspn(users[*count].forecast.advice, "\n")] = 0;

    strcpy(users[*count].forecast.sign, sign);

    (*count)++;
    printf("User added successfully\n");
}

char* getZodiacSign(char *birthdate) {
    int day, month;
    sscanf(birthdate, "%d/%d", &day, &month);

    if((month == 3 && day >= 21) || (month == 4 && day <= 19)) return "Aries";
    if((month == 4 && day >= 20) || (month == 5 && day <= 20)) return "Taurus";
    if((month == 5 && day >= 21) || (month == 6 && day <= 20)) return "Gemini";
    if((month == 6 && day >= 21) || (month == 7 && day <= 22)) return "Cancer";
    if((month == 7 && day >= 23) || (month == 8 && day <= 22)) return "Leo";
    if((month == 8 && day >= 23) || (month == 9 && day <= 22)) return "Virgo";
    if((month == 9 && day >= 23) || (month == 10 && day <= 22)) return "Libra";
    if((month == 10 && day >= 23) || (month == 11 && day <= 21)) return "Scorpio";
    if((month == 11 && day >= 22) || (month == 12 && day <= 21)) return "Sagittarius";
    if((month == 12 && day >= 22) || (month == 1 && day <= 19)) return "Capricorn";
    if((month == 1 && day >= 20) || (month == 2 && day <= 18)) return "Aquarius";
    return "Pisces";
}

void displayUserHoroscope(User users[], int count, int userIndex) {
    if(count == 0) {
        printf("No users available\n");
        return;
    }

    if(userIndex == -1) {
        printf("\nAvailable users:\n");
        for(int i = 0; i < count; i++) {
            printf("%d. %s (%s)\n", i+1, users[i].name, users[i].zodiacSign);
        }
        printf("Select user number: ");
        scanf("%d", &userIndex);
        getchar();
        userIndex--;
    }

    if(userIndex < 0 || userIndex >= count) {
        printf("Invalid user number\n");
        return;
    }

    printf("\n=== HOROSCOPE FOR %s ===\n", users[userIndex].name);
    printf("Zodiac Sign: %s\n", users[userIndex].zodiacSign);
    printf("Birthdate: %s\n", users[userIndex].birthdate);
    printf("Lucky Color: %s\n", users[userIndex].forecast.luckyColor);
    printf("Lucky Number: %d\n", users[userIndex].forecast.luckyNumber);
    printf("Advice: %s\n", users[userIndex].forecast.advice);
}

void updateZodiacForecast(User users[], int count, char *zodiacSign) {
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(users[i].zodiacSign, zodiacSign) == 0) {
            printf("Enter new lucky color: ");
            fgets(users[i].forecast.luckyColor, sizeof(users[i].forecast.luckyColor), stdin);
            users[i].forecast.luckyColor[strcspn(users[i].forecast.luckyColor, "\n")] = 0;

            printf("Enter new lucky number: ");
            scanf("%d", &users[i].forecast.luckyNumber);
            getchar();

            printf("Enter new advice: ");
            fgets(users[i].forecast.advice, sizeof(users[i].forecast.advice), stdin);
            users[i].forecast.advice[strcspn(users[i].forecast.advice, "\n")] = 0;

            found = 1;
        }
    }
    if(found) {
        printf("Forecast updated for %s\n", zodiacSign);
    } else {
        printf("No users with zodiac sign %s\n", zodiacSign);
    }
}

void displayAllUsers(User users[], int count) {
    if(count == 0) {
        printf("No users to display\n");
        return;
    }
    printf("\n=== ALL USERS ===\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s | Birthdate: %s | Zodiac: %s\n",
               i+1, users[i].name, users[i].birthdate, users[i].zodiacSign);
    }
}
