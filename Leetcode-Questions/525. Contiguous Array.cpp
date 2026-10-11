// APPROACH 1: BRUTE FORCE (THIS WILL GIVE TLE ON LEETCODE)
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int one = 0;
            int zero = 0;
            for (int j = i; j < n; j++) {
                (nums[j] == 0) ? ++zero : ++one;
                if (one == zero) maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
