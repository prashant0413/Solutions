// APPROACH 1: USING RECURSION
// TC: O( (M + N - 2)! / (M - 1)! (N - 1)! )
// SC: O(M + N)
class Solution {
    int maxi;
    int m, n;
private:
    void solve(int i, int j, vector<vector<int>>& grid, int x) {
        x = x ^ grid[i][j];

        if (i == m - 1 && j == n - 1) {
            maxi = min(x, maxi);
            return;
        }

        if (i + 1 <= m - 1)
            solve(i + 1, j, grid, x);
        if (j + 1 <= n - 1)
            solve(i, j + 1, grid, x);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        maxi = INT_MAX;
        solve(0, 0, grid, 0);
        return maxi;
    }
};

// APPROACH 2: USING TABULATION AND BITSET
// TC: O(1024 M N)
// SC: O(1024 M N)
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                bitset<1024> up;
                bitset<1024> left;

                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];

                bitset<1024> combined = up | left;

                for (int value = 0; value < 1024; value++) {
                    if (combined[value]) {
                        int resXor = value ^ grid[i][j];
                        dp[i][j][resXor] = 1;
                    }
                }
            }
        }

        for (int value = 0; value < 1024; value++) {
            if (dp[m - 1][n - 1][value]) return value;
        }

        return -1;
    }
};
