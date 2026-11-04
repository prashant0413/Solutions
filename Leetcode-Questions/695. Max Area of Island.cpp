// APPROACH 1: BFS TRAVERSAL
// TC: O(M . N)
// SC: O(M . N)
class Solution {
    int m;
    int n;
private:
    int bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        int cnt = 0;
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        while (!q.empty()) {
            cnt++;
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = row + drow[k];
                int nc = col + dcol[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc]) {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }

        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxCnt = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (vis[i][j] || grid[i][j] == 0) continue;
                maxCnt = max(maxCnt, bfs(i, j, grid, vis));
            }
        }

        return maxCnt;
    }
};


// APPROACH 2: DFS TRAVERSAL
// TC: O(M . N)
// SC: O(M . N)
class Solution {
    int m, n;
private:
    int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis, int drow[], int dcol[]) {
        vis[row][col] = true;
        int cnt = 1;
        for (int k = 0; k < 4; k++) {
            int nr = row + drow[k];
            int nc = col + dcol[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc]) {
                cnt += dfs(nr, nc, grid, vis, drow, dcol);
            }
        }

        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxCnt = 0;
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (vis[i][j] || grid[i][j] == 0) continue;
                cnt = dfs(i, j, grid, vis, drow, dcol);
                maxCnt = max(maxCnt, cnt);
            }
        }

        return maxCnt;
    }
};
