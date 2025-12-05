// Approach 1
// TC = O(n ^ 2)
// SC = O(1)
class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            long long sum2 = 0;
            for (int j = i + 1; j < n; j++)
            {
                sum2 += nums[j];
            }
            if (sum > 0 && sum2 > 0 && (abs(sum - sum2) & 1) != 1)
                cnt++;
        }
        return cnt;
    }
};
