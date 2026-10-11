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

// APPROACH 2: USING HASHMAP
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        mpp[0] =  -1;
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (mpp.count(sum)) {
                maxLen = max(maxLen, i - mpp[sum]);
            }
            if (mpp.count(sum) == 0) mpp[sum] = i;
        }

        return maxLen;
    }
};
