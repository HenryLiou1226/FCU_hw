#include <stdio.h>
#include <stdlib.h>
int* sortArray(int* nums, int numsSize){
    int i, key, j;
	for (i = 1; i < numsSize; i++) {
		key = nums[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];
			j = j - 1;
		}
		nums[j + 1] = key;
	}
    return nums;
}
int main(void)
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int* res = sortArray(arr,sizeof(arr)/sizeof(int));
    for(size_t i = 0;i < sizeof(arr)/sizeof(int);i++)
    {
        printf("%d ",res[i]);
    }
    return 0;
}