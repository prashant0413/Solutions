// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(N^2)
// SC: O(N^2) + O(N)
class Solution {
    int solve(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>> &dp) {
        if (row == n - 1) return matrix[row][col];

        if (dp[row][col] != -1e9) return dp[row][col];

        int mini = INT_MAX;
        for (int k = -1; k <= 1; k++) {
            int nr = row + 1;
            int nc = col + k;
            if (nc >= 0 && nc < n) {
                mini = min(mini, solve(nr, nc, matrix, n, dp));
            }
        }

        return dp[row][col] = matrix[row][col] + mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, solve(0, i, matrix, n, dp));
        }
        return mini;
    }
};

// APPROACH 2: DP TABULATION
// TC: O(N^2)
// SC: O(N^2)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) dp[i][j] = matrix[i][j];
                else {
                    int mini = INT_MAX;
                    for (int k = -1; k <= 1; k++) {
                        int nr = i - 1;
                        int nc = j + k;
                        if (nc >= 0 && nc < n) mini = min(mini, dp[nr][nc]);
                    }
                    dp[i][j] = matrix[i][j] + mini;
                }
            }
        }

        return *min_element(begin(dp[n - 1]), end(dp[n - 1]));
    }
};

// APPROACH 3: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(N^2)
// SC: O(N)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0) temp[j] = matrix[i][j];
                else {
                    int mini = INT_MAX;
                    for (int k = -1; k <= 1; k++) {
                        int nr = i - 1;
                        int nc = j + k;
                        if (nc >= 0 && nc < n) mini = min(mini, prev[nc]);
                    }
                    temp[j] = matrix[i][j] + mini;
                }
            }
            prev = temp;
        }

        return *min_element(begin(prev), end(prev));
    }
};
