// Approach 1
// TC = O(N*M)
// SC = O(N*M)
class Solution {
    int cnt;

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &vis, int m, int n, int drow[], int dcol[]) {
        vis[row][col] = true;
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, grid, vis, m, n, drow, dcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cntOne = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) cntOne++;
            }
        }

        cnt = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // traversing one row and last row
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis, m, n, drow, dcol);
            }

            if (!vis[m - 1][j] && grid[m - 1][j] == 1) {
                dfs(m - 1, j, grid, vis, m, n, drow, dcol);
            }
        }

        // traversing first col and last col
        for (int j = 0; j < m; j++) {
            if (!vis[j][0] && grid[j][0] == 1) {
                dfs(j, 0, grid, vis, m, n, drow, dcol);
            }

            if (!vis[j][n - 1] && grid[j][n - 1] == 1) {
                dfs(j, n - 1, grid, vis, m, n, drow, dcol);
            }
        }

        return cntOne - cnt;
    }
};
