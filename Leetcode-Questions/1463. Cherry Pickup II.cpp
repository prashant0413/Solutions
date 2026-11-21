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

// APPROACH 2: DP TABULATION
// TC: O(M.N.N)
// SC: O(M.N.N)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int i = m - 1; i >= 0; i--) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    if (j2 == j1) continue;

                    if (i == m - 1) {
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                        continue;
                    }

                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        int new_j1 = j1 + dj1;
                        if (new_j1 < 0 || new_j1 >= n) continue;
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int new_j2 = j2 + dj2;
                            if (new_j2 < 0 || new_j2 >= n || new_j1 == new_j2) continue; 
                            maxi = max(maxi, dp[i + 1][new_j1][new_j2]);
                        }
                    }

                    dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + maxi;
                }
            }
        }

        return dp[0][0][n - 1];
    }
};

// APPROACH 3: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(M.N.N)
// SC: O(N.N)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--) {
            vector<vector<int>> temp(n, vector<int>(n, 0));
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    if (j2 == j1) continue;

                    if (i == m - 1) {
                        temp[j1][j2] = grid[i][j1] + grid[i][j2];
                        continue;
                    }

                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        int new_j1 = j1 + dj1;
                        if (new_j1 < 0 || new_j1 >= n) continue;
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int new_j2 = j2 + dj2;
                            if (new_j2 < 0 || new_j2 >= n || new_j1 == new_j2) continue; 
                            maxi = max(maxi, dp[new_j1][new_j2]);
                        }
                    }

                    temp[j1][j2] = grid[i][j1] + grid[i][j2] + maxi;
                }
            }
            dp = temp;
        }

        return dp[0][n - 1];
    }
};
