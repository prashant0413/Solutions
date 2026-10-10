// APPROACH 1: BRUTE FORCE
// TC: O(N^2)
// SC: O(256)
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (n > m) return "";

        int minLen = INT_MAX;
        int st = -1;

        for (int i = 0; i < m; i++) {
            int freq[256] = {0};
            int cnt = 0;
            for (int j = 0; j < n; j++) freq[t[j]]++;
            for (int j = i; j < m; j++) {
                if (freq[s[j]] > 0) {
                    freq[s[j]]--;
                    cnt++;
                }

                if (cnt == n) {
                    if (j - i + 1 < minLen) {
                        st = i;
                        minLen = j - i + 1;
                    }
                    break;
                }                
            }
        }

        return (st == -1) ? "" : s.substr(st, minLen);
    }
};


// APPROACH 2: SLIDING WINDOW
// TC: O(N)
// SC: O(256)
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (n > m) return "";

        int freq[256] = {0};
        for (char c: t) freq[c]++;

        int minLen = 1e6;
        int st = -1;

        int l, r;
        r = l = 0;
        int cnt = 0;
        while (r < m) {
            if (freq[s[r]] > 0) cnt++;
            freq[s[r]]--;

            while (cnt == n) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    st = l;
                }

                freq[s[l]]++;
                if (freq[s[l]] > 0) cnt--;
                l++;
            }

            r++;
        }

        return st == -1 ? "" : s.substr(st, minLen);
    }
};
