// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (char &c: word) {
            if (c >= 'A' && c <= 'Z')
                cnt++;
        }
        if (cnt == 0 || cnt == word.size())
            return true;
        if (cnt == 1) {
            return (word[0] >= 'A' && word[0] <= 'Z');
        }
        return false;
    }
};
