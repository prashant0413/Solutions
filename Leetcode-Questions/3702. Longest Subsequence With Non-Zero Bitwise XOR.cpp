// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) cnt0++;
            x ^= nums[i];
        }
        return cnt0 == n ? 0 : (x == 0) ? n - 1 : n;
    }
};
