// APPROACH 1: RECURSION
// TC: O(2^N)
// SC: O(N)
class Solution {
    bool solve(int i, vector<int> &arr, int sum) {
        if (sum == 0) return true;
        if (i == 0) return arr[0] == sum;
        
        // take
        if (arr[i] <= sum && solve(i - 1, arr, sum - arr[i])) return true;
        // not take
        return solve(i - 1, arr, sum);
    }
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return solve(n - 1, arr, sum);
    }
};

// APPROACH 2: RECURSION WITH MEMOIZATION
// TC: O(SUM.N)
// SC: O(SUM.N) + O(N)
class Solution {
    bool solve(int i, vector<int> &arr, int sum,  vector<vector<int>> &dp) {
        if (sum == 0) return true;
        if (i == 0) return arr[0] == sum;
        
        if (dp[i][sum] != -1e9) return dp[i][sum];
        
        // take
        if (arr[i] <= sum && solve(i - 1, arr, sum - arr[i], dp)) return dp[i][sum] = true;
        // not take
        return dp[i][sum] = solve(i - 1, arr, sum, dp);
    }
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1e9));
        return solve(n - 1, arr, sum, dp);
    }
};
