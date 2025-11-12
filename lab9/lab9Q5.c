#include <stdio.h>
void AD(int *arr, int n, int *max, int *min, float *avg) {
    int sum = 0;
    *max = *min = *arr;
    for (int i=0; i<n; i++) {
        if (arr[i] > *max)
            *max =arr[i];
        if (arr[i] < *min)
            *min =arr[i];
        sum +=arr[i];
    }
    *avg = (float)sum / n;
    return;
}

int main() {
    int data[5] = {40, 50, 60, 75, 80};
    int n = 5, max, min;
    float avg;

    AD(data, n, &max, &min, &avg);
    printf("Max = %d\n", max);
    printf("Min = %d\n", min);
    printf("Avg = %.2f\n", avg);

    return 0;
}
