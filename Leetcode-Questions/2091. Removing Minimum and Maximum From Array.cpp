// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int mini = nums[0];
        int maxi = nums[0];
        int minIdx = 0;
        int maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (mini > nums[i]) {
                mini = nums[i];
                minIdx = i;
            }

            if (maxi < nums[i]) {
                maxi = nums[i];
                maxIdx = i;
            }
        }

        bool maxFromBegin = true;
        bool minFromBegin = true;

        if (abs(maxIdx - 0 + 1) > abs(n - maxIdx)) {
            maxFromBegin = false;
        }

        if (abs(minIdx - 0 + 1) > abs(n - minIdx)) {
            minFromBegin = false;
        }

        if (maxFromBegin && minFromBegin) return max(maxIdx - 0 + 1, minIdx - 0 + 1);
        if (!maxFromBegin && !minFromBegin) return max(n - maxIdx, n - minIdx);
      
        if (maxFromBegin && !minFromBegin) {
            int t = abs(maxIdx + 1) + abs(n - minIdx);
            int b = minIdx + 1;
            int e = n - maxIdx;
            if (b < e && b < t) return b;
            if (e < b && e < t) return e;
            return t; 
        }
        int t = n - maxIdx + minIdx + 1;
        int b = maxIdx + 1;
        int e = n - minIdx;
        if (b <= e && b < t) return b;
        if (e < b && e < t) return e;
        return t; 
    }
};
