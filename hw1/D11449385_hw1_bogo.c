#include<stdio.h>  
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
bool is_sorted(int *array, int arraySize)//check the array is sorted or not
{
    while ( --arraySize >= 1 ) 
    {
        if ( array[arraySize] < array[arraySize-1] )
        { 
            return false;
        }
    }
    return true;
}
void shuffle(int *array, int arraySize)//random shuffle the array if the array is not sorted
{
    int origin,after_shuffle;
    for(int i = 0; i < arraySize; i++) 
    {
        origin = array[i];
        after_shuffle = rand() % arraySize;
        array[i] = array[after_shuffle];
        array[after_shuffle] = origin;
    }
}
 
int* bogosort(int* array, int arraySize)
{
    while ( !is_sorted(array, arraySize) )//keep shuffle the array until it is sorted
    {
        shuffle(array, arraySize);
    }
    return array;//The array is sorted, return to the main function
}
 
int main(void)
{
    time_t t;
    srand((unsigned) time(&t));
    int array[] = { 12, 11, 13, 5, 6 };
    int len = sizeof(array)/sizeof(array[0]);//count the length of the array
    int* sortedArray = bogosort(array, len);
    for(size_t i = 0;i < sizeof(array)/sizeof(int);i++)
    {
        printf("%d ",sortedArray[i]);//print out the Array that has been sorted
    }
    return 0;
}
