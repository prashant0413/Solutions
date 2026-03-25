// Approach 1
// TC = O(2^n)
// SC = O(n)
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// Approach 2
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n ,dp);
    }
};

// Approach 3
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }        
        return dp[n];
    }
};

// Approach 4
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        int prev1 = 0;
        int prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};
