// Approach 1
// TC = O(N^2)
// SC = O(1)

class Solution {
public:
    bool check(vector<int> &freq) {
        int common = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            if (common == 0)
                common = freq[i];
            if (freq[i] != common)
                return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(3, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if (check(freq)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
