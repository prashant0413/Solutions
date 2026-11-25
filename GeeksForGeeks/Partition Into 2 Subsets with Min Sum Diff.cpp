// APPROACH 1: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(SUM.N)
// SC: O(SUM)
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(begin(arr), end(arr), 0);
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        dp[arr[0]] = true;
        for (int i = 1; i < n; i++) {
            vector<bool> temp(sum + 1, false);
            temp[0] = true;
            for (int k = 1; k <= sum; k++) {
                bool take = arr[i] <= k ? dp[k - arr[i]] : false;
                bool notTake = dp[k];
                temp[k] = take || notTake;
            }
            dp = temp;
        }
        
        int mini = 1e9;
        for (int s1 = 0; s1 <= sum / 2; s1++) {
            if (dp[s1]) {
                mini = min(mini, abs(sum - 2 * s1));
            }
        }
        
        return mini;
    }
};
