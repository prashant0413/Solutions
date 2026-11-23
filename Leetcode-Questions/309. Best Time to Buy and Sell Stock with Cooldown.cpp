// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(2.N)
// SC: O(N) + O(2.N)
class Solution {
    int solve(int i, bool buy, vector<int> &prices, int n, vector<vector<int>> &dp) {
        if (i >= n) return 0;

        if (dp[i][buy] != -1e9) return dp[i][buy];

        if (buy) {
            return dp[i][buy] = max(-prices[i] + solve(i + 1, 0, prices, n, dp), solve(i + 1, 1, prices, n, dp));
        }
        return dp[i][buy] = max(prices[i] + solve(i + 2, 1, prices, n, dp), solve(i + 1, 0, prices, n, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1e9));
        return solve(0, 1, prices, n, dp);
    }
};
