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
