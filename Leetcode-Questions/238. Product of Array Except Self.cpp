// APPROACH 1: USING PREFIX PRODUCT
// TC: O(N)
// SC: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int zero = 0;
        int prod = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero++;
            else {
               prod *= nums[i]; 
            }
        }

        vector<int> ans(n, 0);
        if (zero > 1) return ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) ans[i] = prod;
            else {
                ans[i] = (zero) ? 0 : prod / nums[i];
            }
        }

        return ans;
    }
};
