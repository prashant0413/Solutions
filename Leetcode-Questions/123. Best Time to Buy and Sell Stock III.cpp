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

// APPROACH 2: DP TABULATION
// TC: O(2.3.N)
// SC: O(2.3.N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};
