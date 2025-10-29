#include <stdio.h>

int main() {
    int n;
    printf("Enter size of board: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nOriginal Board:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            int t=a[i][j];
            a[i][j]=a[i][n-1-j];
            a[i][n-1-j]=t;
        }
    }
    printf("\nRotated Board:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
