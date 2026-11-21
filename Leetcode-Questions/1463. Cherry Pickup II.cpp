// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(M.N.N)
// SC: O(M) + O(M.N.N)
class Solution {
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>> &dp) {
        if (i == m - 1) {
            return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1e9) return dp[i][j1][j2];

        // EXPLORE ALL PATH TOGETHER
        int maxi = -1e9;
        for (int k = -1; k <= 1; k++) {
            int new_j1 = j1 + k;
            if (new_j1 < 0 || new_j1 >= n) continue;
            for (int t = -1; t <= 1; t++) {
                int new_j2 = j2 + t;
                if (new_j2 < 0 || new_j2 >= n || new_j2 == new_j1) continue;
                maxi = max(maxi, solve(i + 1, new_j1, new_j2, grid, m, n, dp));
            }
        }

        return dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1e9)));
        return solve(0, 0, n - 1, grid, m, n, dp);
    }
};
