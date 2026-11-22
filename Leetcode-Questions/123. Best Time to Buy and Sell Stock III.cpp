// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(2.3.N)
// SC: O(N) + O(2.3.N)
class Solution {
    int solve(int i, bool buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp) {
        if (cap == 0) return 0;
        if (i == n) return 0;

        if (dp[i][buy][cap] != -1e9) return dp[i][buy][cap];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solve(i + 1, false, cap, prices, n, dp), solve(i + 1, true, cap, prices, n, dp));
        } else {
            profit = max(profit,
                     max(prices[i] + solve(i + 1, true, cap - 1, prices, n, dp), solve(i + 1, false, cap, prices, n, dp))
            );
        }
        return dp[i][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1e9)));
        return solve(0, true, 2, prices, n, dp);
    }
};
