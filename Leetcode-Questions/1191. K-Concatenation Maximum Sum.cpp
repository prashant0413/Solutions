// APPROACH 1: USING KADANE'S ALOGRITHM
// TC: O(3N + N)
// SC: O(1)
class Solution {
public:
    int kadane(vector<int> &arr, int n, int k) {
        int sum = 0;
        int maxSum = 0;
        for (int i = 0; i < k * n; i++) {
            if (sum < 0) sum = 0;
            sum += arr[i % n];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        int mod = 1e9 + 7;

        // CASE 1: IF K IS EQUAL TO 1.
        if (k == 1) return kadane(arr, n, 1) % mod;

        // total sum of array
        int totalSum = accumulate(begin(arr), end(arr), 0);

        // CASE 2: IF TOTAL SUM IS LESS THAN ZERO
        if (totalSum < 0) return kadane(arr, n, 2) % mod;

        // CASE 3: IF TOTAL SUM IS POSITIVE
        return ((kadane(arr, n, 2) % mod) + (1LL * (k - 2) * totalSum) % mod) % mod;
    }
};
