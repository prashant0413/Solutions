// APPROACH 1: RECURSION WITH DP MEMOIZATION
// TC: O(M.N)
// SC: O(M + N) + O(M.N)
class Solution {
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];
        
        int cnt = 0;
        // up
        int nr = i - 1;
        int nc = j;
        if (nr >= 0 && obstacleGrid[nr][nc] == 0) {
            cnt += solve(nr, nc, obstacleGrid, m, n, dp);
        }

        // left
        nr = i;
        nc = j - 1;
        if (nc >= 0 && obstacleGrid[nr][nc] == 0) {
            cnt += solve(nr, nc, obstacleGrid, m, n, dp);
        }

        return dp[i][j] = cnt;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, obstacleGrid, m, n, dp);
    }
};

// APPROACH 2: DP TABULATION
// TC: O(M.N)
// SC: O(M.N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0 || obstacleGrid[i][j] == 1) continue;
                int cnt = 0;
                if (i > 0 && obstacleGrid[i - 1][j] == 0) cnt += dp[i - 1][j];
                if (j > 0 && obstacleGrid[i][j - 1] == 0) cnt += dp[i][j - 1];
                dp[i][j] = cnt;
            }
        }

        return dp[m - 1][n - 1];
    }
};
