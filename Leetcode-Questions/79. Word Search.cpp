// APPROACH 1: USING BACKTRACKING
// TC: O(4^(M N))
// SC: O(M N)
class Solution {
    int m, n;
public:
    bool backTrack(int i, int j, int idx, vector<vector<char>>& board, string word, vector<vector<int>> &dir) {
        if (idx >= word.size()) return true;
        char c = board[i][j];
        board[i][j] = '#';

        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (board[nr][nc] == word[idx]) {
                    if (backTrack(nr, nc, idx + 1, board, word, dir)) {
                        board[i][j] = c;
                        return true;
                    } 
                }
            }
        }

        board[i][j] = c;
        return false;
    }

    bool solve(vector<vector<char>>& board, string word) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (backTrack(i, j, 1, board, word, dir)) return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        return solve(board, word);
    }
};
