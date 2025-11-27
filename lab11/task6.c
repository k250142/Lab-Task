#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char category[30];
    int quantity;
} Item;

void task6Menu();
void addItem(Item items[], int *count);
void displayInventory(Item *items, int count);
void filterInventoryByCategory(Item *items, int count, char *category);
void filterInventoryByQuantity(Item *items, int count, int minQuantity);

int main() {
    task6Menu();
    return 0;
}

void task6Menu() {
    Item items[100];
    int count = 0;
    int choice;

    while(1) {
        printf("\n--- TASK 6: WAREHOUSE INVENTORY SYSTEM ---\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Filter by Category\n");
        printf("4. Filter by Quantity\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: addItem(items, &count); break;
            case 2: displayInventory(items, count); break;
            case 3: {
                char category[30];
                printf("Enter category: ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = 0;
                filterInventoryByCategory(items, count, category);
                break;
            }
            case 4: {
                int minQuantity;
                printf("Enter minimum quantity: ");
                scanf("%d", &minQuantity);
                getchar();
                filterInventoryByQuantity(items, count, minQuantity);
                break;
            }
            case 5: return;
            default: printf("Invalid choice\n");
        }
    }
}

void addItem(Item items[], int *count) {
    if(*count >= 100) {
        printf("Maximum items reached\n");
        return;
    }
    printf("Enter item name: ");
    fgets(items[*count].name, sizeof(items[*count].name), stdin);
    items[*count].name[strcspn(items[*count].name, "\n")] = 0;

    printf("Enter category: ");
    fgets(items[*count].category, sizeof(items[*count].category), stdin);
    items[*count].category[strcspn(items[*count].category, "\n")] = 0;

    printf("Enter quantity: ");
    scanf("%d", &items[*count].quantity);
    getchar();

    (*count)++;
    printf("Item added successfully\n");
}

void displayInventory(Item *items, int count) {
    if(count == 0) {
        printf("No items to display\n");
        return;
    }
    printf("\n=== WAREHOUSE INVENTORY ===\n");
    Item *ptr = items;
    for(int i = 0; i < count; i++) {
        printf("%d. %s | Category: %s | Quantity: %d\n",
               i+1, ptr->name, ptr->category, ptr->quantity);
        ptr++;
    }
}

void filterInventoryByCategory(Item *items, int count, char *category) {
    printf("\n=== ITEMS IN CATEGORY: %s ===\n", category);
    int found = 0;
    Item *ptr = items;
    for(int i = 0; i < count; i++) {
        if(strcmp(ptr->category, category) == 0) {
            printf("%s | Quantity: %d\n", ptr->name, ptr->quantity);
            found = 1;
        }
        ptr++;
    }
    if(!found) printf("No items found\n");
}

void filterInventoryByQuantity(Item *items, int count, int minQuantity) {
    printf("\n=== ITEMS WITH QUANTITY >= %d ===\n", minQuantity);
    int found = 0;
    Item *ptr = items;
    for(int i = 0; i < count; i++) {
        if(ptr->quantity >= minQuantity) {
            printf("%s | Category: %s | Quantity: %d\n", ptr->name, ptr->category, ptr->quantity);
            found = 1;
        }
        ptr++;
    }
    if(!found) printf("No items found\n");
}
