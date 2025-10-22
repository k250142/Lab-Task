#include <stdio.h>
int main() {
    char str[100];
    int i, v = 0, c = 0;
    printf("Enter a word or code: ");
    gets(str);
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i]>='A' && str[i]<='Z')
            str[i] = str[i] + 32;
        if(str[i]>='a' && str[i]<='z') {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                v++;
            else
                c++;
        }
    }
    printf("Vowels: %d\n", v);
    printf("Consonants: %d\n", c);
    printf("Your word is converted into Small alphabets: \n");
    puts(str);
    return 0;
}
