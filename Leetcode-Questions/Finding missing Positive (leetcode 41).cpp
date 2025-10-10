class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        bool one = false;

        // checking if one present or not
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                one = true;

            if (nums[i] < 1 || n < nums[i])
                nums[i] = 1;
        }
        // if one not present
        if (one == false)
            return 1;

        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]);
            if (index >= 1 && index <= n)
                nums[index - 1] = -abs(nums[index - 1]);
        }

        // finding missing element
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};
