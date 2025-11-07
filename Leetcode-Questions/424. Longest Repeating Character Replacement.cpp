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
