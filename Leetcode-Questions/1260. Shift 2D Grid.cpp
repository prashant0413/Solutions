// Approach 1
// TC = O(k*m*n)
// Sc = O(m*n)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> newGrid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                newGrid[i][j] = grid[i][j];

        for (int shift = 0; shift < k; shift++) {
            int ele = newGrid[m - 1][n - 1];
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == 0 && j == 0)
                        newGrid[0][0] = ele;
                    else if (j == 0) {
                        newGrid[i][j] = newGrid[i - 1][n - 1];
                    } else {
                        newGrid[i][j] = newGrid[i][j - 1];
                    }
                }
            }
        }

        return newGrid;
    }
};
