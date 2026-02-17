// Approach 1
// TC = O(n)
// SC = O(1)
class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int cnt = 0;
        int maxCnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                cnt++;
            if (s[i] == ')')
                cnt--;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;
    }
};
