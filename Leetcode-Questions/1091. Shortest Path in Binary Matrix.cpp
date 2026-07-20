// Approach 1
// TC = O(n * n)
// SC = O(n * n)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) return -1;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        dis[0][0] = 1;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int w = q.front().second;
            q.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nr = r + i;
                    int nc = c + j;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && dis[nr][nc] > w + 1 && grid[nr][nc] == 0) {
                        dis[nr][nc] = w + 1;
                        q.push({{nr, nc}, w + 1});
                    }
                }
            }
        }

        return dis[n - 1][n - 1] == 1e9 ? -1 : dis[n - 1][n - 1];
    }
};
