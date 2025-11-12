#include <stdio.h>
void UV(int x) {
    x = x + 5;
}
void UR(int *x) {
    *x = *x + 5;
}

int main() {
    int num = 80;

    printf("Before update value: %d\n", num);
    UV(num);
    printf("After update value: %d\n", num);
    printf("Before update reference: %d\n", num);
    UR(&num);
    printf("After update reference: %d\n", num);

    return 0;
}
