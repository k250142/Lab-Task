#include<stdio.h>
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
      *returnSize=numsSize;
      int temp=0;
      int j=0;
      for(int i=0; i< numsSize-2; i++){
         temp=nums[n+j];
        nums[n+j]=nums[i+1];
        nums[i+1]=temp;
        if(i==n){
            j++;
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
    int* a=shuffle(nums , n, n/2 , &n);
     for(int i = 0; i < n; i++){
        printf("%d  ", *(a+i));
    }

   return 0;
}