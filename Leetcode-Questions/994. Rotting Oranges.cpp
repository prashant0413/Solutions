// Approach 1
// TC = O(m * n)
// SC = O(m * n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        int cntFresh = 0;
        int cnt = 0;
        // {{r, c}, t}
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1)
                    cntFresh++;
                vis[i][j] = grid[i][j];
            }
        }

        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for (int k = 0; k < 4; k++) {
                int nr = row + drow[k];
                int nc = col + dcol[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && vis[nr][nc] != 2) {
                    vis[nr][nc] = 2;
                    cnt++;
                    q.push({{nr, nc}, t + 1});
                }
            }
        }
        if (cntFresh - cnt != 0) return -1;
        return time;
    }
};
