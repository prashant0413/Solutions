// APPROACH 1: USING SLIDING WINDOW
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        int l, r;
        l = r = 0;
        int prod = 1;
        while (r < n) {
            prod *= nums[r];
            while (l <= r && prod >= k) {
                prod = prod / nums[l];
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }
};
