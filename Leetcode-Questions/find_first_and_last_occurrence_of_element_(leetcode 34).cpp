// APPROACH 1: USING BINARY SEARCH
// TC: O(LOG N)
// SC: O(1)
class Solution {
public:
    int findLast(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }

    int findFirst(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    } 
};
