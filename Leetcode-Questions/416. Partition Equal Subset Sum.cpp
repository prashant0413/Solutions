// APPROACH 1: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(N) + O(SUM.N)
// SC: O(SUM)
class Solution {
    bool solve(vector<int> &nums, int n, int sum) {
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        if (nums[0] <= sum)
            dp[nums[0]] = true;
        for (int i = 1; i < n; i++) {
            vector<bool> temp(sum + 1, 0);
            temp[0] = true;
            if (nums[0] <= sum)
                temp[nums[0]] = true;
            for (int target = 1; target <= sum; target++) {
                bool take = nums[i] <= target ? dp[target - nums[i]] : false;
                bool notTake = dp[target];
                temp[target] = take || notTake;
            }
            dp = temp;
        }

        return dp[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum != sum / 2 * 2) return false;
        return solve(nums, n, sum / 2);
    }
};
