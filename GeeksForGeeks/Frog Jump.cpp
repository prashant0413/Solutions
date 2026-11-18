// APPROACH 1: RECURSION
// TC: O(2^N)
// SC: O(N)
class Solution {
    int solve(int i, vector<int> &height, int n, int cost) {
        if (i == n - 1) return cost;
        int left = solve(i + 1, height, n, cost + abs(height[i] - height[i + 1]));
        int right = i + 2 <= n - 1 ? solve(i + 2, height, n, cost + abs(height[i] - height[i + 2])) : INT_MAX;
        return min(left, right);
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        return solve(0, height, n, 0);
    }
};

// APPROACH 2: RECURSION WITH DP - TOP TO BOTTOM
// TC: O(N)
// SC: O(N)
class Solution {
    int solve(int i, vector<int> &height, int n, vector<int> &dp) {
        if (i == n - 1) return 0;
        if (dp[i] != -1) return dp[i];
        int left = abs(height[i] - height[i + 1]) + solve(i + 1, height, n, dp);
        int right = i + 2 <= n - 1 ? abs(height[i] - height[i + 2]) + solve(i + 2, height, n, dp) : INT_MAX;
        return dp[i] = min(left, right);
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(0, height, n, dp);
    }
};

// APPROACH 3: DP - BOTTOM TO TOP
// TC: O(N)
// SC: O(N)
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            int fs = dp[i - 1] + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;
            if (i > 1) ss = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(fs, ss);
        }
        return dp[n - 1];
    }
};

// APPROACH 4: DP - BOTTOM TO TOP WITH SPACE OPTIMIZATION
// TC: O(N)
// SC: O(`)
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev1 = 0;
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int fs = prev1 + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;
            if (i > 1) ss = prev2 + abs(height[i] - height[i - 2]);
            int curr = min(fs, ss);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
