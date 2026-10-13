// APPROACH 1: USING SET
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int &i: nums) {
            if (st.count(i)) return i;
            st.insert(i);
        }
        return -1;
    }
};
