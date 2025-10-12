class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        int maxLen = 0;
        int s_ = 0;
        int f = 0;
        while (f < n) {
            if (mpp.find(s[f]) != mpp.end() && mpp[s[f]] >= s_) {
                int idx = mpp[s[f]];
                mpp[s[f]] = f;
                s_ = idx + 1;
            } else {
                mpp[s[f]] = f;
                maxLen = max(maxLen, f - s_ + 1);
            }
            f++;
        }
        return maxLen;
    }
};

// TC = O(N)
// SC = O(N) => O(min(n, k)) ≈ O(1)
