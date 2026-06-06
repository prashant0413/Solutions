// Approach 1
// TC = O(2N)
// SC = O(N)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> sufSum(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            sufSum[i] = nums[i + 1] + sufSum[i + 1];
        }

        vector<int> result(n ,0);
        int preSum = 0;
        for (int i = 0; i < n; i++) {
            result[i] = abs(sufSum[i] - preSum);
            preSum += nums[i];
        }

        return result;
    }
};
