class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        // if array has only one element
        if (n == 1)
            return nums[0];

        // checking boundary conditions
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        // array is trimmed down
        int low = 1;
        int high = nums.size() - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // elimination left half
            if (mid % 2 == 0 && nums[mid] == nums[mid + 1] || mid % 2 == 1 && nums[mid] == nums[mid - 1])
                low = mid + 1;
            // elimination right half
            else
                high = mid - 1;
        }
        return -1;
    }
};
