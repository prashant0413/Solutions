// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        unordered_set<int> st;
        for (int i: nums)
            st.insert(i);

        vector<int> ans;
        for (int i = mini; i <= maxi; i++) {
            if (st.count(i) == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
