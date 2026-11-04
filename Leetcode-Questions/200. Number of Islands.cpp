// APPROACH 1: DFS TRAVERSAL
// TC: O(M . N)
// SC: O(M . N)
class Solution {
    int m;
    int n;
private:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis, int drow[], int dcol[]) {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int nr = i + drow[k];
            int nc = j + dcol[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == '1') {
                dfs(nr, nc, grid, vis, drow, dcol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] || grid[i][j] == '0') continue;
                cnt++;
                dfs(i, j, grid, vis, drow, dcol);
            }
        }

        return cnt;
    }
};
