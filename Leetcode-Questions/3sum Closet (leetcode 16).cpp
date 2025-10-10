class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int result;
        int closetSum = nums[0] + nums[1] + nums[2];
        int closetDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            // skips duplicate
            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                    return target;
                if (sum < target)
                    left++;
                else
                    right--;

                int diff = abs(target - sum);
                if (diff < closetDiff)
                {
                    closetDiff = diff;
                    closetSum = sum;
                    result = sum;
                }
            }
        }
        return result;
    }
}
