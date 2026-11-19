// APPROACH 1: RECURSION WITH DP - TOP TO BOTTOM
// TC: O(N)
// SC: O(N)
class Solution {
private:
    int solve(int i, vector<int> &nums, vector<int> &dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int maxi = 0;
        maxi = nums[i] + max(maxi, solve(i + 2, nums, dp));
        maxi = max(maxi, solve(i + 1, nums, dp));
        return dp[i] = maxi;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};

// APPROACH 2: DP TABULATION (BOTTOM UP)
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int take = nums[i] + ((i > 1) ? dp[i - 2] : 0);
            int notTake = 0 + dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }
};
