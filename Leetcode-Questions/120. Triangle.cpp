// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(N)
// SC: O(N) + O(M.N)
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
