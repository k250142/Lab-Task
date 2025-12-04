#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i;
    printf("Enter number of feedback entries: ");
    scanf("%d", &n);
    getchar();

    char **fb = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++) {
        fb = (char**)realloc(fb, (i+1) * sizeof(char*));
        char temp[200];
        printf("Enter feedback %d: ", i+1);
        fgets(temp, 200, stdin);
        temp[strcspn(temp, "\n")] = 0;
        fb[i] = (char*)malloc(strlen(temp)+1);
        strcpy(fb[i], temp);
    }

    int totalChars = 0, maxIndex = 0;
    for(i = 0; i < n; i++) {
        totalChars += strlen(fb[i]);
        if(strlen(fb[i]) > strlen(fb[maxIndex])) maxIndex = i;
    }

    printf("Total characters: %d\n", totalChars);
    printf("All feedback:\n");
    for(i = 0; i < n; i++) printf("%s\n", fb[i]);
    printf("Longest feedback: %s\n", fb[maxIndex]);

    for(i = 0; i < n; i++) free(fb[i]);
    free(fb);
    return 0;
}
