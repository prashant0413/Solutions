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
