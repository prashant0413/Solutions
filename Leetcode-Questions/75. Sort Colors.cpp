// APPROACH 1: NAIVE
// TC: O(2N)
// SC: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i: nums) {
            if (i == 0) cnt0++;
            else if (i == 1) cnt1++;
        }

        for (int i = 0; i < n; i++) {
            if (cnt0 > 0) {
                nums[i] = 0;
                cnt0--;
            } else if (cnt1 > 0) {
                nums[i] = 1;
                cnt1--;
            } else {
                nums[i] = 2;
            }
        }
    }
};

// APPROACH 2: DUTCH'S NATIONAL FLAG ALGORITHM
// TC: O(N)
// SC: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
