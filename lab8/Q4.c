#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int r, c;
    printf("Enter rows and cols of hall: ");
    scanf("%d%d", &r, &c);
    int hall[r][c];
    srand(time(0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            hall[i][j] = rand()%2;
            printf("%d ", hall[i][j]);
        }
        printf("\n");
    }
    int totalEmpty=0, maxEmpty=0, rowMax=0;
    for(int i=0;i<r;i++){
        int emptyRow=0;
        for(int j=0;j<c;j++){
            if(hall[i][j]==0) emptyRow++;
        }
        totalEmpty += emptyRow;
        if(emptyRow > maxEmpty){
            maxEmpty = emptyRow;
            rowMax = i+1;
        }
    }
    printf("Total Available Seats: %d\n", totalEmpty);
    printf("Row with Most Empty Seats: Row %d (%d empty seats)\n", rowMax, maxEmpty);
    return 0;
}
