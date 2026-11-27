// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(N.SUM)
// SC: O(N) + O(N.SUM)
class Solution {
    int solve(int i, vector<int> &arr, int diff, int sum, int s1, vector<vector<int>> &dp) {
        if (i == 0) {
            int take = s1 + arr[i];
            int notTake = s1 + 0;
            int cnt = 0;
            if (sum - 2 * take == diff) cnt += 1;
            if (sum - 2 * notTake == diff) cnt += 1;
            return cnt;
        }
        
        if (dp[i][s1] != -1e9) return dp[i][s1];
        
        int cnt = 0;
        cnt += solve(i - 1, arr, diff, sum, s1 + arr[i], dp);
        cnt += solve(i - 1, arr, diff, sum, s1, dp);
        
        return dp[i][s1] = cnt;
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = accumulate(begin(arr), end(arr), 0);
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1e9));
        return solve(n - 1, arr, diff, sum, 0, dp);
    }
};
