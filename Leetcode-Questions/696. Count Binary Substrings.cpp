// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int res = 0;
        int curr = 1;
        int prev = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                res += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }
        return res + min(curr, prev);
    }
};
