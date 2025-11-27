#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char word[100];
} Word;

void task4Menu();
void reverseStringRecursive(char *str, int start, int end);
void isPalindromeRecursive(char *str, int start, int end);

int main() {
    task4Menu();
    return 0;
}

void task4Menu() {
    Word word;
    int choice;

    while(1) {
        printf("\n--- TASK 4: WORD ANALYSIS SYSTEM ---\n");
        printf("1. Analyze Word\n");
        printf("2. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: {
                printf("Enter a word: ");
                fgets(word.word, sizeof(word.word), stdin);
                word.word[strcspn(word.word, "\n")] = 0;

                printf("\nOriginal word: %s\n", word.word);

                printf("Reversed word: ");
                reverseStringRecursive(word.word, 0, strlen(word.word) - 1);
                printf("\n");

                printf("Is palindrome: ");
                isPalindromeRecursive(word.word, 0, strlen(word.word) - 1);
                printf("\n");
                break;
            }
            case 2: return;
            default: printf("Invalid choice\n");
        }
    }
}

void reverseStringRecursive(char *str, int start, int end) {
    if(start >= end) return;
    printf("%c", str[end]);
    reverseStringRecursive(str, start, end - 1);
}

void isPalindromeRecursive(char *str, int start, int end) {
    if(start >= end) {
        printf("Yes, it is a palindrome\n");
        return;
    }
    if(tolower(str[start]) != tolower(str[end])) {
        printf("No, it is not a palindrome\n");
        return;
    }
    isPalindromeRecursive(str, start + 1, end - 1);
}
