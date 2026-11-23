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

// APPROACH 2: DP TABULATION
// TC: O(2.N)
// SC: O(2.N)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy)
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                else
                    dp[i][buy] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
            }
        }

        return dp[0][1];
    }
};

// APPROACH 3: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(2.N)
// SC: O(2)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp(2, 0);
            for (int buy = 0; buy <= 1; buy++) {
                if (buy)
                    temp[buy] = max(-prices[i] + dp[0], dp[1]);
                else
                    temp[buy] = max(prices[i] - fee + dp[1], dp[0]);
            }
            dp = temp;
        }

        return dp[1];
    }
};
