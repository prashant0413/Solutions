class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        // if array has only one element
        if (n == 1)
            return 0;
        // checking boundarty conditions
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1;
        int high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // if mid is peak element
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            // if mid is on increasing slope
            if (nums[mid] > nums[mid - 1])
                low = mid + 1;
            // if mid is on decreasing slope
            else
                high = mid - 1;
        }
        return -1;
    }
};
