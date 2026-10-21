// APPROACH 1: REVERSE TECHNIQUE
// TC: O(N)
// SC: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(begin(nums), end(nums));
        reverse(begin(nums), begin(nums) + k);
        reverse(begin(nums) + k, end(nums));
    }
};
