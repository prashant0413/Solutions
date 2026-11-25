// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(TARGET.N)
// SC: O(N) + O(TARGET.N)
class Solution {
    int solve(int i, vector<int> &arr, int target, int n, vector<vector<int>> &dp) {
        if (i == n) return 0 == target;
        
        if (dp[i][target] != -1) return dp[i][target];
        
        int cnt = 0;
        if (arr[i] <= target)
            cnt += solve(i + 1, arr, target - arr[i], n, dp);
        cnt += solve(i + 1, arr, target, n, dp);
        return dp[i][target] = cnt;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, arr, target, n, dp);
    }
};
