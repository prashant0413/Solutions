// APPROACH 1: USING BINARY ON ANSWERS
// TC: O(N LOG N)
// SC: O(1)
class Solution {
public:
    bool findSub(int target, vector<int> &nums, int k) {
        int n = nums.size();
        long long sum = 0;
        int i, j;
        i = j = 0;

        while (j < n) {
            sum += nums[j];
            if (j - i + 1 > k) {
                sum -= nums[i];
                i++;
            }

            if ((j - i + 1 == k) && (sum >= target)) return true;
            j++;
        }

        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int low = 1;
        int high = n;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (findSub(target, nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans == -1 ? 0 : ans;
    }
};
