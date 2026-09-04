// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sufMin(n);
        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < sufMin[i + 1]) {
                sufMin[i] = nums[i];
            } else {
                sufMin[i] = sufMin[i + 1];
            }
        }

        int stIdx = -1;
        int score = INT_MAX;

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if (maxi - sufMin[i] <= k) {
                if (stIdx != -1 && stIdx < i)
                    continue;
                stIdx = i;
                score = maxi - sufMin[i];
            }
        }

        return stIdx;
    }
};
