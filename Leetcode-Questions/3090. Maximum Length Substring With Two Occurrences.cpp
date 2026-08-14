// Approach 1
// TC = O(N^2)
// SC = O(1)
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                if (mpp[s[j]] > 2) break;
                bool allTwo = true;
                for (auto it: mpp) {
                    char c = it.first;
                    int cnt = it.second;
                    if (cnt > 2) {
                        allTwo = false;
                        break;
                    }
                }
                if (allTwo) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
