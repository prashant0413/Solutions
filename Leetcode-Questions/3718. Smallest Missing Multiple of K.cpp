// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i = 1;
        while (st.count(k * i) == 1) {
            i++;
        }
        return i * k;
    }
};
