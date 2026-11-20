// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(M.N)
// SC: O(M + N) + O(M.N)
class Solution {
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];
        int cnt = 0;
        
        // up
        int nr = i - 1;
        int nc = j;
        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            cnt += solve(nr, nc, m, n, dp);
        }

        // left
        nr = i;
        nc = j - 1;
        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            cnt += solve(nr, nc, m, n, dp);
        }
        
        return dp[i][j] = cnt;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return  solve(m - 1, n - 1, m, n, dp);
    }
};

// APPROACH 2: DP TABULATION 
// TC: O(M.N)
// SC: O(M.N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int cnt = 0;
                cnt += (i - 1 < 0) ? 0 : dp[i - 1][j];
                cnt += (j - 1 < 0) ? 0 : dp[i][j - 1];
                dp[i][j] = cnt;
            }
        }

        return dp[m - 1][n - 1];
    }
};
