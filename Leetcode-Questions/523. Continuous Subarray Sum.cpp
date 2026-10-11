// APPROACH 1: BRUTE FORCE (THIS GIVE TLE ON LEETCODE)
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                if (sum % k == 0) return true;
            }
        }

        return false;
    }
};

// APPROACH 2: USING HASHMAP WITH MODULO
// TC: O(N)
// SC: O(K)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mpp.count(sum % k)) {
                if (i - mpp[sum % k] >= 2) return true;
            }
            if (mpp.count(sum % k) == 0)
                mpp[sum % k] = i;
        }

        return false;
    }
};
