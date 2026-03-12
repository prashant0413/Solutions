// Approach 1
// TC = O(n^3)
// SC = O(1)
class Solution {
public:
    bool checkSpecial(vector<vector<int>>& mat, int i, int j, int m, int n) {
        for (int row = 0; row < m; row++) {
            if (mat[row][j] == 1 && row != i) {
                return false;
            }
        }

        for (int col = 0; col < n; col++) {
            if (mat[i][col] == 1 && col != j) {
                return false;
            }
        }

        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && checkSpecial(mat, i, j, m, n)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
