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

// APPROACH 3: DP TABULATION
// TC: O(SUM.N)
// SC: O(SUM.N)
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        for (int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                bool notTake = dp[i - 1][target];
                bool take = arr[i] <= target ? dp[i - 1][target - arr[i]] : false;
                dp[i][target] = take || notTake;
            }
        }
        
        return dp[n - 1][sum];
    }
};

// APPROACH 4: DP TABULATION WITH SPACE OPTIMIZATION
// TC: O(SUM.N)
// SC: O(SUM)
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        dp[arr[0]] = true;
        
        for (int i = 1; i < n; i++) {
            vector<bool> temp(sum + 1, false);
            temp[0] = true;
            temp[arr[0]] = true;
            for (int target = 1; target <= sum; target++) {
                bool notTake = dp[target];
                bool take = arr[i] <= target ? dp[target - arr[i]] : false;
                temp[target] = take || notTake;
            }
            dp = temp;
        }
        
        return dp[sum];
    }
};
