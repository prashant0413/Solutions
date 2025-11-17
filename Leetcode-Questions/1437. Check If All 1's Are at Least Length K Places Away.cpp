class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int idx = -1;
        int i = 0;
        while (i < nums.size() && nums[i] != 1) {
            i++;
        }
        idx = i;
        i++;
        while (i < nums.size()) {
            if (nums[i]) {
                if (i - 1 - idx < k)
                    return false;
                idx = i;
            }
            i++;
        }
        return true;
    }
};
