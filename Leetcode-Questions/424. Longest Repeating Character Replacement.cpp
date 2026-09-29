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

// APPROACH 2: USING SLIDING WINDOW
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        
        int l, r;
        l = r = 0;
        int maxLen = 0;
        int mf = 0;
        int freq[26] = {0};

        while (r < n) {
            freq[s[r] - 'A']++;
            mf = max(mf, freq[s[r] - 'A']);

            if ((r - l + 1) - mf > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            if ((r - l + 1) - mf <= k) {
                maxLen = max(maxLen, r - l + 1);
            }

            r++;
        }

        return maxLen;
    }
};
