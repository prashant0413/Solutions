// Approach 1
// TC = O(m*n)
// SC = O(m*n)
class Solution {
public:
    void bfs(int sr, int sc, int color, vector<vector<int>>& image, int m, int n) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[sr][sc] = 1;
        int stColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if (nr >= 0 && nr < m && nc >=0 && nc < n && image[nr][nc] == stColor && vis[nr][nc] != 1) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        } 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> copyImage(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                copyImage[i][j] = image[i][j];
        }

        bfs(sr, sc, color, copyImage, m, n);
        return copyImage;
    }
};
