// APPROACH 1: USING RECURSION WITH MEMOIZATION
// TC: O(M . N . (M + N))
// SC: O(M + N)
class Solution {
    int m, n;
    int t[101][101][201];
public:
    bool solve(int i, int j, vector<vector<char>>& grid, int cnt) {
        if (grid[i][j] == '(') cnt++;
        if (grid[i][j] == ')') cnt--;

        if (cnt < 0) return false;

        if (t[i][j][cnt] != -1) return t[i][j][cnt];

        if (i >= m - 1 && j >= n - 1) {
            return t[i][j][cnt] = cnt == 0;
        }

        int r_i = i;
        int r_j = j + 1;
        if (r_i < m && r_j < n && grid[r_i][r_j] != '0') {
            if(solve(r_i, r_j, grid, cnt)) {
                return t[i][j][cnt] = true;
            }
        }

        int d_i = i + 1;
        int d_j = j;
        if (d_i < m && d_j < n && grid[d_i][d_j] != '0') {
            if(solve(d_i, d_j, grid, cnt)) {
                return t[i][j][cnt] = true;
            }
        }

        return t[i][j][cnt] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        if ((m + n - 1) & 1) return false;
        return solve(0, 0, grid, 0);
    }
};

// APPROACH 2: USING TABULATION
// TC: O(M . N . (M + N))
// SC: O(M + N)
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) & 1) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        bool t[101][101][201];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cnt = 0; cnt <= i + j + 1; cnt++) {
                    if (i == m - 1 && j == n - 1) {
                        t[i][j][cnt] = (cnt == 0);
                        continue;
                    }

                    t[i][j][cnt] = false;

                    // down
                    if (i + 1 < m) {
                        int newCnt = (grid[i + 1][j] == '(') ? cnt + 1 : cnt - 1;
                        if (newCnt >= 0 && t[i + 1][j][newCnt]) {
                            t[i][j][cnt] = true;
                        }
                    }

                    // right
                    if (j + 1 < n) {
                        int newCnt = (grid[i][j + 1] == '(') ? cnt + 1 : cnt - 1;
                        if (newCnt >= 0 && t[i][j + 1][newCnt]) {
                            t[i][j][cnt] = true;
                        }
                    }
                }
            }
        }

        return t[0][0][1];
    }
};
