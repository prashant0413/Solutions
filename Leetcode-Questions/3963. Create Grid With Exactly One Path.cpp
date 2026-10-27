// APPROACH 1: BRUTE FORCE
// TC: O(M) + O(N)
// SC: O(1)
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));
        for (int i = 0; i < m; i++) {
            res[i][0] = '.';
        }
        for (int j = 1; j < n; j++) {
            res[m - 1][j] = '.';
        }

        return res;
    }
};
