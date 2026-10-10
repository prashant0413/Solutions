// APPROACH 1: PREFIX SUM
// TC: O(N)
// SC: O(1)
class NumArray {
    vector<int> ans;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0) ans.push_back(ans[i - 1] + nums[i]);
            else ans.push_back(nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return ans[right] - ((left - 1 >= 0) ? ans[left - 1] : 0);
    }
};
