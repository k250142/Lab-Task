#include <stdio.h>
int main() {
    int n, i, last;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
    	scanf("%d", &arr[i]);
	}
    last = arr[n - 1];
    for(i = n-1; i > -1 ; i--) {
    	int temp =arr[i];
    	arr[i] = arr[i-1];
    	arr[i-1]=temp;
	}
    arr[0] = last;
    printf("Array after right rotation:\n");
    for(i = 0; i < n; i++) {
    	printf("%d ", arr[i]);
	}
    return 0;
}
