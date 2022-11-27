#include <stdio.h>
#include <stdlib.h>
int* bubblesort(int* array, int arrSize)//use bubblesort to sort the array
{
    for(size_t size = 1;size < arrSize;size++)
    {
        for(size_t loop = 0;loop < arrSize-size;loop++)
        {
            if(array[loop]>array[loop+1])//swap the value if left value is bigger then the right
            {
                int temp = array[loop];
                array[loop]=array[loop+1];
                array[loop+1]=temp;
            }
        }
    }
    return array;//The array is sorted, return to the main function
}
int main(void)
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int* sortedArray = bubblesort(arr,sizeof(arr)/sizeof(int));//use another Array to get the return sorted array from function quickSort
    for(size_t i = 0;i < sizeof(arr)/sizeof(int);i++)
    {
        printf("%d ",sortedArray[i]);//print out the Array that has been sorted
    }
    return 0;
}
