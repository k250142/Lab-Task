#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char type[30];
    float price;
    int quantity;
} Gift;

void task1Menu();
void addGift(Gift gifts[], int *count);
void displayGifts(Gift gifts[], int count);
void filterByPrice(Gift gifts[], int count, float minPrice);
void filterByQuantity(Gift gifts[], int count, int minQuantity);

int main() {
    task1Menu();
    return 0;
}

void task1Menu() {
    Gift gifts[100];
    int count = 0;
    int choice;

    while(1) {
        printf("\n--- TASK 1: GIFT MANAGEMENT ---\n");
        printf("1. Add Gift\n");
        printf("2. Display All Gifts\n");
        printf("3. Filter by Price\n");
        printf("4. Filter by Quantity\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: addGift(gifts, &count); break;
            case 2: displayGifts(gifts, count); break;
            case 3: {
                float minPrice;
                printf("Enter minimum price: ");
                scanf("%f", &minPrice);
                getchar();
                filterByPrice(gifts, count, minPrice);
                break;
            }
            case 4: {
                int minQuantity;
                printf("Enter minimum quantity: ");
                scanf("%d", &minQuantity);
                getchar();
                filterByQuantity(gifts, count, minQuantity);
                break;
            }
            case 5: return;
            default: printf("Invalid choice\n");
        }
    }
}

void addGift(Gift gifts[], int *count) {
    if(*count >= 100) {
        printf("Maximum gifts reached\n");
        return;
    }
    printf("Enter gift name: ");
    fgets(gifts[*count].name, sizeof(gifts[*count].name), stdin);
    gifts[*count].name[strcspn(gifts[*count].name, "\n")] = 0;

    printf("Enter gift type: ");
    fgets(gifts[*count].type, sizeof(gifts[*count].type), stdin);
    gifts[*count].type[strcspn(gifts[*count].type, "\n")] = 0;

    printf("Enter price: ");
    scanf("%f", &gifts[*count].price);

    printf("Enter quantity: ");
    scanf("%d", &gifts[*count].quantity);
    getchar();

    (*count)++;
    printf("Gift added successfully\n");
}

void displayGifts(Gift gifts[], int count) {
    if(count == 0) {
        printf("No gifts to display\n");
        return;
    }
    printf("\n=== ALL GIFTS ===\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s | Type: %s | Price: %.2f | Quantity: %d\n",
               i+1, gifts[i].name, gifts[i].type, gifts[i].price, gifts[i].quantity);
    }
}

void filterByPrice(Gift gifts[], int count, float minPrice) {
    printf("\n=== GIFTS ABOVE PRICE %.2f ===\n", minPrice);
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(gifts[i].price >= minPrice) {
            printf("%s | Type: %s | Price: %.2f | Quantity: %d\n",
                   gifts[i].name, gifts[i].type, gifts[i].price, gifts[i].quantity);
            found = 1;
        }
    }
    if(!found) printf("No gifts found\n");
}

void filterByQuantity(Gift gifts[], int count, int minQuantity) {
    printf("\n=== GIFTS WITH QUANTITY >= %d ===\n", minQuantity);
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(gifts[i].quantity >= minQuantity) {
            printf("%s | Type: %s | Price: %.2f | Quantity: %d\n",
                   gifts[i].name, gifts[i].type, gifts[i].price, gifts[i].quantity);
            found = 1;
        }
    }
    if(!found) printf("No gifts found\n");
}
