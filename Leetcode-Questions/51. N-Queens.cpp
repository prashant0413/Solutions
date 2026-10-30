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

// APPROACH 2: USING BACKTRACKING WITH OPTIMIZATION
// TC: O(N!)
// SC: O(N) + O(N^2) + O(5N)
class Solution {
public:
    void solve(int row, vector<string> &arr, vector<vector<string>> &res, int n, vector<bool> &column, vector<bool> &leftDiag, vector<bool> &rightDiag) {
        if (row == n) {
            res.push_back(arr);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!column[col] && !leftDiag[n - 1 + col - row] && !rightDiag[row + col]) {
                column[col] = true;
                leftDiag[n - 1 + col - row] = true;
                rightDiag[row + col] = true;

                arr[row][col] = 'Q';
                solve(row + 1, arr, res, n, column, leftDiag, rightDiag);
                arr[row][col] = '.';

                column[col] = false;
                leftDiag[n - 1 + col - row] = false;
                rightDiag[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> arr(n, string(n, '.'));

        vector<bool> column(n, false);
        vector<bool> leftDiag(2 * n - 1, false);
        vector<bool> rightDiag(2 * n - 1, false);

        solve(0, arr, res, n, column, leftDiag, rightDiag);
        return res;
    }
};
