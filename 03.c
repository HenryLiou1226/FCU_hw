#include <stdio.h>
#include <stdlib.h>
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int* sortArray(int* nums, int numsSize){
    int min_idx;
    for (int i = 0; i < numsSize-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		
		for (int j = i+1; j < numsSize; j++){
			if (nums[j] < nums[min_idx]){
					min_idx = j;
			}
		}
		// Swap the found minimum element with the first element
		swap(&nums[min_idx], &nums[i]);
	}
    return nums;
}
int main(void)
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int* sortedArray = sortArray(arr,sizeof(arr)/sizeof(int));
    for(size_t i = 0;i < sizeof(arr)/sizeof(int);i++)
    {
        printf("%d ",sortedArray[i]);
    }
    return 0;
}