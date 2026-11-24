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
