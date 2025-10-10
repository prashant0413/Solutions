int removeDuplicates(int* nums, int numsSize) {
    int count = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(i<numsSize-1 && nums[i] == nums[i+1])
            continue;
        else
        {
            nums[count++] = nums[i];
        }
    }
    return count;
}
