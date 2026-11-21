// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(N)
// SC: O(N) + O(N^2)
class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &triangle, int n,  vector<vector<int>> &dp) {
        if (i == n - 1) return triangle[i][j];

        if (dp[i][j] != -1e9) return dp[i][j];

        int mini = INT_MAX;
        for (int k = 0; k <= 1; k++) {
            int row = i + 1;
            int col = j + k;
            mini = min(mini, solve(row, col, triangle, n, dp));
        }

        return dp[i][j] = triangle[i][j] + mini;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1e9));
        return solve(0, 0, triangle, n, dp);
    }
};

// APPROACH 2: DP TABULATION
// TC: O(N^2)
// SC: O(N^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == n - 1) {
                    dp[i][j] = triangle[i][j];
                    continue;
                }

                int mini = min(dp[i + 1][j], dp[i + 1][j + 1]);
                dp[i][j] = triangle[i][j] + mini;
            }
        }

        return dp[0][0];
    }
};

// APPROACH 3: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(N^2)
// SC: O(N)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp(n, 0);
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == n - 1) {
                    temp[j] = triangle[i][j];
                    continue;
                }

                int mini = min(dp[j], dp[j + 1]);
                temp[j] = triangle[i][j] + mini;
            }
            dp = temp;
        }

        return dp[0];
    }
};
