#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, maxIndex = 0;
    printf("Enter number of movie categories: ");
    scanf("%d", &n);

    int *r = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++) {
        printf("Enter ratings for category %d: ", i);
        scanf("%d", &r[i]);
    }

    int total = 0;
    for(i = 0; i < n; i++) {
        total += r[i];
        if(r[i] > r[maxIndex]) maxIndex = i;
    }

    printf("Total ratings: %d\n", total);
    printf("Average ratings: %.2f\n", (float)total/n);
    printf("Highest rating category index: %d\n", maxIndex);

    int idx, newVal;
    printf("Enter category index to update: ");
    scanf("%d", &idx);
    printf("Enter new rating: ");
    scanf("%d", &newVal);
    r[idx] = newVal;

    printf("Updated ratings: ");
    for(i = 0; i < n; i++) printf("%d ", r[i]);

    free(r);
    return 0;
}
