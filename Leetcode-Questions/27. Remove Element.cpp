// APPROACH 1:
// TC: O(N)
// SC: O(1)
int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    for(int i=0; i<numsSize; i++) {
        if(nums[i] != val)
            nums[count++] = nums[i];
    }
    return count;
}
