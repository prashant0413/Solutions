// Approach 1
// TC = O(n ^ 2)
// SC = O(1)
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxLen = 0;
        for (int i = 0; i < arr.size(); i++) {
            int sum = 0;
            for (int j = i; j < arr.size(); j++) {
                sum += arr[j];
                if (sum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};

// Approach 2
// TC = O(n)
// SC = O(n)
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxLen = 0;
        int n = arr.size();
        unordered_map<int, int> preSum;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }
            
            int rem = sum - k;
            if (preSum.find(rem) != preSum.end()) {
                int len = i - preSum[rem];
                maxLen = max(maxLen, len);
            }
            
            if (preSum.find(sum) == preSum.end()) {
                preSum[sum] = i;
            }
        }
        return maxLen;
    }
};
