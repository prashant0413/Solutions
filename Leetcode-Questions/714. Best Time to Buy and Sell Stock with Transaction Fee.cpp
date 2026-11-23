// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(N)
// SC: O(N) + O(2.N)
class Solution {
    int solve(int i, int buy, int n, vector<int> &prices, int fee, vector<vector<int>> &dp) {
        if (i == n) return 0;

        if (dp[i][buy] != -1e9) return dp[i][buy];

        if (buy)
            return dp[i][buy] = max(-prices[i] + solve(i + 1, false, n, prices, fee, dp), solve(i + 1, true, n, prices, fee, dp));
        return dp[i][buy] = max(prices[i] - fee + solve(i + 1, true, n, prices, fee, dp), solve(i + 1, false, n, prices, fee, dp));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1e9));
        return solve(0, true, n, prices, fee, dp);
    }
};
