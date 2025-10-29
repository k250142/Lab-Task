#include <stdio.h>

int main() {
    char words[3][10];
    int i, j, count = 0;
    printf("Enter 3 words:\n");
    for(i=0;i<3;i++){
        scanf("%s", words[i]);
    }
    for(i=0;i<3;i++){
        for(j=0; words[i][j] != '\0'; j++){
            char c = words[i][j];
            if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                count++;
            }
        }
    }
    printf("Total vowels: %d\n", count);
    return 0;
}
