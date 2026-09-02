// Approach 1
// TC = O(n)
// SC = O(1)
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(begin(nums1), end(nums1));
        if (mini & 1) return true;

        for (int i: nums1) {
            if (i & 1) {
                return false;
            }
        }

        return true;
    }
};
