// Approach 1
// TC = O(M*N)
// SC = O(M*N)
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>> &vis, int drow[], int dcol[], int m, int n) {
        vis[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && board[nr][nc] == 'O') {
                dfs(nr, nc, board, vis, drow, dcol, m, n);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // traversing first row and last row
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, board, vis, drow, dcol, m, n);
            }

            if (!vis[m - 1][j] && board[m - 1][j] == 'O') {
                dfs(m - 1, j, board, vis, drow, dcol, m, n);
            }
        }

        // traversing first col and last col
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, board, vis, drow, dcol, m, n);
            }

            if (!vis[i][n - 1] && board[i][n - 1] == 'O') {
                dfs(i, n - 1, board, vis, drow, dcol, m, n);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
