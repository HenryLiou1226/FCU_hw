#include <stdio.h>
#include <stdlib.h>

int temp;
int* selectionSort(int* nums, int numsSize){
    for (int step = 0;step < numsSize; step++)
	{
		// Find the minimum element in unsorted array
		for (int min_index = step+1; min_index < numsSize; min_index++){
			if (nums[min_index] < nums[step]){
				temp = nums[min_index];
				nums[min_index] = nums[step];
				nums[step] = temp;
			}
		}
		// Swap the found minimum element with the first element
	}
    return nums;
}
int main(void)
{
    int arr[] = { 13, 11, 12, 5, 6 };
    int* sortedArray = selectionSort(arr,sizeof(arr)/sizeof(int));//use another Array to get the return sorted array from function selectionSort
    for(size_t i = 0;i < sizeof(arr)/sizeof(int);i++)
    {
        printf("%d ",sortedArray[i]);//print out the Array that has been sorted
    }
    return 0;
}