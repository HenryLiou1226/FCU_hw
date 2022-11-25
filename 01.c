#include <stdio.h>
#include <stdlib.h>
int* bubblesort(int* array, int arrSize)//use bubblesort to sort the array
{
    for(size_t i = 1;i < arrSize;i++)
    {
        for(size_t j = 0;j < arrSize-i;j++)
        {
            if(array[j]>array[j+1])//swap the value if left value is bigger then the right
            {
                int temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    return array;//The array is sorted, return to the main function
}
int main(void)
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int* sortedArr = bubblesort(arr,sizeof(arr)/sizeof(int));//use another Array to get the return sorted array from function quickSort
    for(size_t i = 0;i < sizeof(arr)/sizeof(int);i++)
    {
        printf("%d ",sortedArr[i]);//print out the Array that has been sorted
    }
    return 0;
}
/* ans for leetcode
int* sortArray(int* nums, int numsSize, int* returnSize){
    for(size_t i = 1;i < numsSize;i++)
    {
        for(size_t j = 0;j < numsSize-i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                int temp = nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    *returnSize = numsSize;
    return nums;
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    
    int *res = (int*)calloc(numsSize,sizeof(int));
    memmove(res,nums,sizeof(int)*numsSize);
    for(size_t i = 1;i < numsSize;i++)
    {
        for(size_t j = 0;j < numsSize-i;j++)
        {
            if(res[j]>res[j+1])
            {
                int temp = res[j];
                res[j]=res[j+1];
                res[j+1]=temp;
            }
        }
    }
    *returnSize = numsSize;
    return res;
}
*/