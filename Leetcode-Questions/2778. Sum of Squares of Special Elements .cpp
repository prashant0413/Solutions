// APPROACH 1: BRUTE FORCE
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (n % (i + 1) == 0) ? nums[i] * nums[i] : 0;
        }
        return sum;
    }
};
