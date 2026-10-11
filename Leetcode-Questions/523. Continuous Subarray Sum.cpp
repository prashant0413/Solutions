// APPROACH 1: BRUTE FORCE
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
