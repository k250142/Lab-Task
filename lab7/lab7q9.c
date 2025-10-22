#include <stdio.h>
#include <string.h>
int main() {
    char str[200], word[50], longest[50];
    int i = 0, j = 0, maxLen = 0;
    printf("Enter a sentence: ");
    gets(str);
    for(i = 0; i <= strlen(str); i++) {
        if(str[i] == ' ' || str[i] == '\0') {
            word[j] = '\0';
            if(strlen(word) > maxLen) {
                maxLen = strlen(word);
                strcpy(longest, word);
            }
            j = 0;
        } else {
            word[j++] = str[i];
        }
    }
    printf("Longest word: %s\n", longest);
    return 0;
}
