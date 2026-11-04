// APPROACH 1: BFS TRAVERSAL
// TC: O(M . N)
// SC: O(M . N)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        queue<pair<pair<int, int>, int>> q; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first.first;
                int col = q.front().first.second;
                int d = q.front().second;
                q.pop();
                res[row][col] = d;
                for (int k = 0; k < 4; k++) {
                    int nr = row + drow[k];
                    int nc = col + dcol[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                        q.push({{nr, nc}, d + 1});
                        vis[nr][nc] = true;
                    }
                }
            }
        }

        return res;
    }
};
