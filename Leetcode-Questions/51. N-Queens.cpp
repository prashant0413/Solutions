class Solution {
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &rows, 
        vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
            if (col == n) {
                ans.push_back(board);
                return;
            }

            for (int row = 0; row < n; row++) {
                if (rows[row] == 0 && lowerDiagonal[row + col] == 0 && 
                upperDiagonal[n - 1 + col - row] == 0) {
                    board[row][col] = 'Q';
                    rows[row] = 1;
                    lowerDiagonal[row + col] = 1;
                    upperDiagonal[n - 1 + col - row] = 1;
                    solve(col + 1, board, ans, rows, upperDiagonal, lowerDiagonal, n);
                    board[row][col] = '.';
                    rows[row] = 0;
                    lowerDiagonal[row + col] = 0;
                    upperDiagonal[n - 1 + col - row] = 0;
                }
            }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> row(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, row, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};
