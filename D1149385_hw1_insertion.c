#include <stdio.h>
#include <stdlib.h>
int* insertionSort(int* array, int arrSize){
    int key , index;
	for (int step = 1; step < arrSize; step++) // start from 1 because the first number is already sorted
	{
		key = array[step];// keep the numsSize[step] as key
		index = step - 1;// The index run from step - 1 because 0 to step - 1 is already sorted
		while (index >= 0 && array[index] > key) 
		{
			array[index + 1] = array[index];// find the correct index to keep as key
			index = index - 1;
		}
		array[index + 1] = key;// put the key number in the correct index
	}
    return array;//The array is sorted, return to the main function
}
int main(void)
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int* sortedArray = insertionSort(arr,sizeof(arr)/sizeof(int));
    for(size_t i = 0;i < sizeof(arr)/sizeof(int);i++)
    {
        printf("%d ",sortedArray[i]);//print out the Array that has been sorted
    }
    return 0;
}
