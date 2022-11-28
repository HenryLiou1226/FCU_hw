#include <stdio.h>
#include <stdlib.h>
int compare(const void*a,const void*b)//using function qsort need to define a function to compare the two number
{
    return (*(int*)a - *(int*)b);
}
int* quickSort(int* array, int arrSize)
{
    qsort(array,arrSize,sizeof(int),compare);//using function qsort from <stdlib.h> to sort the array
    return array;//The array is sorted, return to the main function
}
int main(void)
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int* sortedArray = quickSort(arr,sizeof(arr)/sizeof(int));//use another Array to get the return sorted array from function quickSort
    for(size_t i = 0;i < sizeof(arr)/sizeof(int);i++)
    {
        printf("%d ",sortedArray[i]);//print out the Array that has been sorted
    }
    return 0;
}