class Solution {
    bool solve(int n, vector<int>& arr, int k, int i, int s) {
        if (s == k) {
            return true;
        }
        
        if (i >= n || s > k) {
            return false;
        }
        
        if (solve(n, arr, k, i + 1, s + arr[i]))
            return true;

        if (solve(n, arr, k, i + 1, s))
            return true;
            
        return false;
    }
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return solve(n, arr, k, 0, 0);       
    }
};
