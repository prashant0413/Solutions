// APPROACH 1: USING BACKTRACKING
// TC: O(N . N!)
// SC: O(N) + O(N^2)
class Solution {
public:
    bool isPossible(int row, int col, vector<string> &arr, int n) {
        // checking column
        for (int r = 0; r < n; r++) {
            if (arr[r][col] == 'Q') return false;
        }

        // checking left diagonal
        int rowLeft = row - 1;
        int colLeft = col - 1;
        while (rowLeft < n && rowLeft >= 0 && colLeft >= 0 && colLeft < n) {
            if (arr[rowLeft][colLeft] == 'Q') return false;
            rowLeft--;
            colLeft--;
        }

        // checking right diagonal
        int rowRight = row - 1;
        int colRight = col + 1;
        while (rowRight < n && rowRight >= 0 && colRight >= 0 && colRight < n) {
            if (arr[rowRight][colRight] == 'Q') return false;
            rowRight--;
            colRight++;
        }

        return true;
    } 

    void solve(int row, vector<string> &arr, vector<vector<string>> &res, int n) {
        if (row == n) {
            res.push_back(arr);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isPossible(row, col, arr, n)) {
                arr[row][col] = 'Q';
                solve(row + 1, arr, res, n);
                arr[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> arr(n, string(n, '.'));
        solve(0, arr, res, n);
        return res;
    }
};


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
