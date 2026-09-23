// APPROACH 1: PREFIX SUM + HASHMAP
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mpp[sum] = i;
        }

        if (sum < x) return -1;
        if (sum == x) return n;

        int remaining = sum - x;
        int maxLen = 0;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mpp.count(sum - remaining)) {
                maxLen = max(maxLen, i - mpp[sum - remaining]);
            }
        }

        return maxLen != 0 ? n - maxLen : -1;
    }
};
