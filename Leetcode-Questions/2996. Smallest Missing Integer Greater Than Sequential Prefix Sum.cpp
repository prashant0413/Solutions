// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                sum += nums[i];
            } else {
                break;
            }
        }
        unordered_set<int> st;
        for (int i: nums) {
            st.insert(i);
        }
        while (st.count(sum)) {
            sum++;
        }
        return sum;
    }
};
