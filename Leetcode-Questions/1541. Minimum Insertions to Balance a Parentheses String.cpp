// APPROACH 1
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        int ans = 0;
        int cnt = 0;

        int i = 0;
        while (i < n) {
            if (s[i] == '(') cnt++;
            else {
                if (cnt > 0) cnt--;
                else ans += 1;

                if (i + 1 < n && s[i + 1] == ')') i++;
                else ans += 1;
            }
            i++;
        }

        return ans + cnt * 2;;   
    }
};
