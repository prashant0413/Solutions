// Approach 1
// TC = O(N^2)
// SC = O(N^2)
class Solution {
    vector<pair<int, int>> dir;

    void bfs(int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = true;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto k: dir) {
                int nr = r + k.first;
                int nc = c + k.second;
                if ((nr >= 0 && nr < m) && (nc >= 0 && nc < n) && grid[nr][nc] == '1') {
                    if (!vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

public:
    Solution() { dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int cnt = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1' && !vis[row][col]) {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};
