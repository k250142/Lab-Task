#include <stdio.h>
int main() {
    int n, i, j, num;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter number to delete: ");
    scanf("%d", &num);
    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            for(j = i; j < n - 1; j++) {
            	arr[j] = arr[j + 1];
                 n--; i--;
			}
        }
    }
    printf("Array after deleting element:\n");
    for(i = 0; i < n; i++) 
	{
	   printf("%d ", arr[i]);	
	}
    return 0;
}
