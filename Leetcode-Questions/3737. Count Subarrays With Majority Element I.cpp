// Approach 1
// TC = O(N^2)
// SC = O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = i; j < n; j++) {
                if (target == nums[j]) c++;
                if (c > (j - i + 1) / 2) cnt++;
            }
        }
        return cnt;
    }
};
