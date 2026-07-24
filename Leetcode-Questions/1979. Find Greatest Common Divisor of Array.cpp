// Approach 1
// TC = O(n + log(b))
// SC = O(1)
class Solution {
public:
    int hcf(int a, int b) {
        if (b % a == 0) return a;
        return hcf(b % a, a);
    }

    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[1];
        for (int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        return hcf(mini, maxi);
    }
};
