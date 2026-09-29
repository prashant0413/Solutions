// APPROACH 1: USING BRUTE FORCE
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            int mf = 0;
            for (int j = i; j < n; j++) {
                freq[s[j] - 'A']++;
                mf = max(mf, freq[s[j] - 'A']);
                if (j - i + 1 - mf <= k) {
                    maxLen = max(maxLen, j - i + 1);
                } else {
                    break;
                }
            }
        }

        return maxLen;
    }
};

// APPROACH 2: ? 
// TC: O(?)
// SC: O(?)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l,r;
        l = r = 0;
        int maxLen = 0;
        vector<int> arr(26, 0);
        int maxFreq = 0;
        while (r < s.length()) {
            arr[s[r] - 'A']++;
            maxFreq = max(maxFreq, arr[s[r] - 'A']);
            while ((r - l + 1) - maxFreq > k) {
                arr[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
