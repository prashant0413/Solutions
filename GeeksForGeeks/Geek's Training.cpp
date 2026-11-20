// APPROACH 1: RECURSION WITH MEMOIZATION
// TC: O(N)
// SC: O(N) + O(3N)
class Solution {
private:
    int solve(int i, vector<vector<int>>& mat, int n, int lastIdx, vector<vector<int>> &dp) {
        if (i >= n) return 0;
        if (lastIdx != -1 && dp[i][lastIdx] != -1) return dp[i][lastIdx];
        int maxi = 0;
        for (int ch = 0; ch < 3; ch++) {
            if (ch == lastIdx) continue;
            maxi = max(maxi, mat[i][ch] + solve(i + 1, mat, n, ch, dp));
        }
        return lastIdx != -1 ? dp[i][lastIdx] = maxi : maxi;
    }
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(0, mat, n, -1, dp);
    }
};

// APPROACH 2: DP TABULATION (BOTTOM UP)
// TC: O(4N)
// SC: O(4N)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        
        for (int i = 1; i < n; i++) {
            for (int last = 0; last < 4; last++) {
                for (int tasks = 0; tasks < 3; tasks++) {
                    if (tasks == last) continue;
                    dp[i][last] = max(dp[i][last], dp[i - 1][tasks] + mat[i][tasks]);
                }
            }
        }
        
        return dp[n - 1][3];
    }
};
