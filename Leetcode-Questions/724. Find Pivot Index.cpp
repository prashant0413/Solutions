// APPROACH 1: USING PREFIX SUM
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> sufSum(n, 0);
        for (int i = n - 1; i >= 1; i--) {
            sufSum[i - 1] = nums[i] + sufSum[i];
        }

        int sum = 0;
        if (sum == sufSum[0]) return 0;
        for (int i = 1; i < n; i++) {
            sum += nums[i - 1];
            if (sum == sufSum[i]) return i;
        }

        return -1;
    }
};
