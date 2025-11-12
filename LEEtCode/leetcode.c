#include<stdio.h>
int* runningSum(int* nums, int numsSize, int* returnSize) {
     int sum=0;
     *returnSize = numsSize;
       for(int i=0; i < numsSize; i++){
           for(int j=i; j <= i; j++){
               nums[i]= sum + nums[j];
           }
           sum=nums[i];
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
    int* a = runningSum(nums , n , &n);
    for(int i = 0; i < n; i++){
        printf("%d  ", *(a+i));
    }

   return 0;
}