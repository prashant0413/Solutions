// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (len == 0 && s[i] == ' ')
                continue;
            if (s[i] == ' ')
                break;
            len++;
        }
        return len;
    }
};
