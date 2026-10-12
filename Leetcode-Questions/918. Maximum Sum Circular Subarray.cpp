// APPROACH 1: USING KADANE'S ALGORITHM
// TC: O(3N)
// SC: O(1)
class Solution {
public:
    int kadaneMin(vector<int> &nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] > nums[i]) sum = 0;
            sum += nums[i];
            minSum = min(minSum, sum);
        }
        return minSum;
    }

    int kadaneMax(vector<int> &nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum < 0) sum = 0;
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // sum of all elements
        int sum = 0;
        for (int i: nums) sum += i;

        // minimum subarray sum
        int mini = kadaneMin(nums);

        // maximum subarray sum
        int maxi = kadaneMax(nums);

        // circular sum
        int circular = sum - mini;

        return (maxi > 0) ? max(maxi, circular) : maxi;
    }
};
