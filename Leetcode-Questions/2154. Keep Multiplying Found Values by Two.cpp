class Solution {
    int search(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] == k)
                return i;
        return -1;
    }
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        while (1) {
            int idx = search(nums, original);
            if (idx == -1)
                return original;
            original *= 2;
        }
        return -1;
    }
};
