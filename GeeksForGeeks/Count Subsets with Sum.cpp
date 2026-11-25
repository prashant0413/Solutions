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

// APPROACH 2: DP TABULATION
// TC: O(N.TARGET)
// SC: O(N.TARGET)
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        dp[0][0] = arr[0] == 0 ? 2 : 1;
        if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
        
        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= target; k++) {
                int cnt = 0;
                cnt += (arr[i] <= k) ? dp[i - 1][k - arr[i]] : 0;
                cnt += dp[i - 1][k];
                dp[i][k] = cnt;
            }
        }
        
        return dp[n - 1][target];
    }
};

// APPROACH 3: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(N.TARGET)
// SC: O(TARGET)
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(target + 1, 0);
        
        dp[0] = arr[0] == 0 ? 2 : 1;
        if (arr[0] != 0 && arr[0] <= target) dp[arr[0]] = 1;
        
        for (int i = 1; i < n; i++) {
            vector<int> temp(target + 1, 0);
            for (int k = 0; k <= target; k++) {
                int cnt = 0;
                cnt += (arr[i] <= k) ? dp[k - arr[i]] : 0;
                cnt += dp[k];
                temp[k] = cnt;
            }
            dp = temp;
        }
        
        return dp[target];
    }
};
