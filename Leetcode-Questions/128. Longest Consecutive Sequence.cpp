// APPROACH : USING SET
// TC: O(2N)
// SC: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (int i: nums) {
            st.insert(i);
        }

        int maxCnt = 0;
        for (auto i: st) {
            if (st.count(i - 1) == 1)
                continue;

            int cnt = 1;
            int j = i + 1;
            while (st.count(j) == 1) {
                cnt++;
                j++;
            }

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
};
