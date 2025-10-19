#include <stdio.h>
int main() {
    int mark, count = 0;
    float sum = 0;
    printf("Enter marks (-1 to stop): ");
    while (1) {
        scanf("%d", &mark);
        if (mark == -1)
            break;
        sum += mark;
        count++;
    }
    if (count > 0)
        printf("Average = %.2f\n", sum / count);
    else
        printf("No marks entered.\n");
    return 0;
}