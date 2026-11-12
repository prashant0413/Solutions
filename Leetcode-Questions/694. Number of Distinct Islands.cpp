// APPROACH 1: USING DFS TRAVERSAL
// TC: O((M.N LOG M.N) + (4.M.N))
// SC: O(M.N)
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &arr, int row0, int col0) {
        int m = grid.size();
        int n = grid[0].size();
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        
        vis[row][col] = true;
        arr.push_back({row - row0, col - col0});
        
        for (int i = 0; i < 4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 'L') {
                dfs(nr, nc, grid, vis, arr, row0, col0);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 'L') {
                    vector<pair<int, int>> arr;
                    dfs(i, j, grid, vis, arr, i, j);
                    st.insert(arr);
                }
            }
        }
        
        return st.size();
    }
};
