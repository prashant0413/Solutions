// APPROACH 1
// TC: O(N)
// SC: O(1)
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();

        vector<int> ans(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                cnt++;
                ans[i] = (cnt & 1) ? 1 : 0;
            } else {
                ans[i] = (cnt & 1) ? 1 : 0;
                cnt--;
            }
        }

        return ans;
    }
};
