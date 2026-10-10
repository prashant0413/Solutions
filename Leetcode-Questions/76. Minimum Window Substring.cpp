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



class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        int cnt = 0;
        int minLen = 1e5;
        int stIdx = -1;
        vector<int> hash(256, 0);
        for (const char &c : t)
            hash[c]++;
        int l = 0, r = 0;
        while (r < m) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            while (cnt == n) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    stIdx = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        return  (stIdx == -1) ? "" : s.substr(stIdx, minLen);
    }
};
