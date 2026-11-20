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
