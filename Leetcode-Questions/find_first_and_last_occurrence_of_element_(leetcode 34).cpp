class Solution
{
    int firstposition(const vector<int> &nums, int target)
    {
        int index = -1;
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                index = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return index;
    }

    int lastposition(const vector<int> &nums, int target)
    {
        int index = -1;
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                index = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return index;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {firstposition(nums, target), lastposition(nums, target)};
    }
};
