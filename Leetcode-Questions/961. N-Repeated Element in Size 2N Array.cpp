// Approach 1
// TC = O(n)
// SC = O(n)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int &i : nums) {
            mpp[i]++;
            if (mpp[i] > 1)
                return mpp[i];
        }
    }
};

// Approach 2
// TC = O(n)
// SC = O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2])
                return nums[i];
        }
        return nums[n - 1];
    }
};
