#include <stdio.h>
#include <stdlib.h>
int temp;
int* selectionSort(int* array, int arrSize)
{
    for (int step = 0;step < arrSize; step++)
    {
	for (int min_index = step+1; min_index < arrSize; min_index++)
	{
		if (array[min_index] < array[step])// Find the minimum element in unsorted array and swap the found minimum element with the first element
		{
			temp = array[min_index];
			array[min_index] = array[step];
			array[step] = temp;
		}
	}
    }
    return array;//The array is sorted, return to the main function
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
