// Approach 1
// TC = O(N*M)
// SC = O(N*M)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    vis[row][col] = true;
                    q.push({{row, col}, 0});
                    ans[row][col] = 0;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    ans[nr][nc] = d + 1;
                    q.push({{nr, nc}, d + 1});
                }
            }
        }
        return ans;
    }
};
