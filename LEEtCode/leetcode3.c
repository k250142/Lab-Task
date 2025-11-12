#include<stdio.h>
int* transformArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for(int i=0; i<numsSize; i++){
         if(nums[i]%2==0)  nums[i]=0;
         else nums[i]=1;
    }
    int temp=0;
     for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize-i-1; j++) {
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    return nums;
}

int main(){
    int n ;
    printf("Enter How Number you want to enter: ");
    scanf("%d",&n);
    int nums[n];
    for(int i = 0; i < n; i++){
        printf("Enter value of no.%d : ", i+1);
        scanf("%d", &nums[i]);
    }
    int* a=transformArray(nums, n, &n);
     for(int i = 0; i < n; i++){
        printf("%d  ", *(a+i));
    }

   return 0;
}