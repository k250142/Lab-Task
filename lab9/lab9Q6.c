#include <stdio.h>

char* formatName(char *first, char *last) {
    static char fullName[100];
    int i=0;
    while(*(first+i) != '\0'){
    	fullName[i]= *(first+i);
    	i++;
	}
	fullName[i]= ' ';
	i++;
	int j=0;
	while(*(last+j) !='\0'){
		fullName[i]= *(last+j);
		j++;
		i++;
	}
	fullName[i]='\0';
    return fullName;
}

int main() {
    char first[50] , last[50];

    printf("Enter first name: ");
    scanf("%s", first);
    printf("Enter last name: ");
    scanf("%s", last);
    char *result = formatName(first , last);
    int i=0;
    printf("Full Name: ");
    while(*(result+i)!='\0'){
    	printf("%c", *(result+i));
        i++;
	}

    return 0;
}
