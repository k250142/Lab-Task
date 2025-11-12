#include <stdio.h>

void fR(int counts[], int n, int target) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (counts[i] + counts[j] == target) {
                printf("\nRoad %d and Road %d  combined traffic is %d\n", i+1, j+1, target);
                return;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter roads: ");
    scanf("%d", &n);

    int counts[n];
    printf("Enter daily vehicle count for each road:\n");
    for (int i=0; i<n; i++) {
        printf("Road %d: ", i+1);
        scanf("%d", &counts[i]);
    }

    int target;
    printf("Enter target vehicle count: ");
    scanf("%d", &target);

    fR(counts, n, target);

    return 0;
}
