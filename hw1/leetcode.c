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

