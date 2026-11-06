// APPROACH 1: DFS TRAVERSAL
// TC: O(M . N)
// SC: O(M . N)
class Solution {
    int m, n;
private:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& board, int drow[], int dcol[]) {
        vis[row][col] = true;
        for (int k = 0; k < 4; k++) {
            int nr = row + drow[k];
            int nc = col + dcol[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && board[nr][nc] == 'O') {
                dfs(nr, nc, vis, board, drow, dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        // FIRST ROW AND LAST ROW
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && board[0][j] == 'O') dfs(0, j, vis, board, drow, dcol);
            if (!vis[m - 1][j] && board[m - 1][j] == 'O') dfs(m - 1, j, vis, board, drow, dcol);
        }

        // FIRST COL AND LAST COL
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && board[i][0] == 'O') dfs(i, 0, vis, board, drow, dcol);
            if (!vis[i][n - 1] && board[i][n - 1] == 'O') dfs(i, n - 1, vis, board, drow, dcol);
        }

        // MARKING UNVISITED 'O' TO 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};
