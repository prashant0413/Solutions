class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pos(n / 2, 0);
        vector<int> neg(n / 2, 0);

        int j = 0, k = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                neg[j++] = nums[i];
                continue;
            }
            pos[k++] = nums[i];
        }

        j = 0, k = 0;
        int i = 0;
        while (i < n)
        {
            nums[i++] = pos[j++];
            nums[i++] = neg[k++];
        }
        return nums;
    }
};
