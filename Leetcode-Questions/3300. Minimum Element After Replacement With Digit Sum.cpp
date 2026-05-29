// Approach 1
// TC = O(nlog(n))
// SC = O(1)
class Solution {
public:
    int sumOfDigits(int n) {
        if (n <= 9)
            return n;
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, sumOfDigits(nums[i]));
        }
        return mini;
    }
};
