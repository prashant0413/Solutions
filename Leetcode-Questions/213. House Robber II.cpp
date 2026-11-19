// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(N)
// SC: O(N) + O(N)
class Solution {
private:
    int solve(int i, vector<int> &nums, int n, vector<int> &dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int pick = nums[i] + solve(i + 2, nums, n, dp);
        int notPick = solve(i + 1, nums, n, dp);
        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n, -1);
        return max(solve(0, nums, n - 1, dp1), solve(1, nums, n, dp2));
    }
};

// APPROACH 2: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(N)
// SC: O(1)
class Solution {
private:
    int robber(vector<int> &nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            int curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) temp2.push_back(nums[i]);
            if (i != n - 1) temp1.push_back(nums[i]);
        }
        return max(robber(temp1), robber(temp2));
    }
};
