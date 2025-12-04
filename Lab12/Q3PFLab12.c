#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int containsDigit(char *str) {
    while(*str) {
        if(isdigit(*str)) return 1;
        str++;
    }
    return 0;
}

int main() {
    int n, i;
    printf("Enter number of usernames: ");
    scanf("%d", &n);
    getchar();

    char **names = (char**)malloc(n * sizeof(char*));

    for(i = 0; i < n; i++) {
        char temp[100];
        printf("Enter username %d: ", i+1);
        fgets(temp, 100, stdin);
        temp[strcspn(temp, "\n")] = 0;
        names[i] = (char*)malloc(strlen(temp)+1);
        strcpy(names[i], temp);
    }

    printf("Valid usernames:\n");
    for(i = 0; i < n; i++) {
        if(!containsDigit(names[i])) printf("%s\n", names[i]);
    }

    for(i = 0; i < n; i++) free(names[i]);
    free(names);
    return 0;
}
