// Approach 1
// TC = O(nlog(n))
// SC = O(n)
class Solution {
public:
    int solve(string &s, char ch1, char ch2) {
        int n = s.length();
        unordered_map<int, int> mpp;
        int cnt1 = 0;
        int cnt2 = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != ch1 && s[i] != ch2) {
                cnt1 = 0;
                cnt2 = 0;
                mpp.clear();
                continue;
            }

            if (s[i] == ch1)
                cnt1++;
            if (s[i] == ch2)
                cnt2++;

            if (cnt1 == cnt2) {
                maxLen = max(maxLen, cnt1 + cnt2);
            }

            if (mpp.count(cnt1 - cnt2)) {
                maxLen = max(maxLen, i - mpp[cnt1 - cnt2]);
            } else {
                mpp[cnt1 - cnt2] = i;
            }
        }
        return maxLen;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        // case 1
        // 'aaaa'
        int cnt = 1; // s[0]
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else {
                maxLen = max(maxLen, cnt);
                cnt = 1;
            }
        }
        maxLen = max(maxLen, cnt);

        // case 2
        maxLen = max(maxLen, solve(s, 'a', 'b'));
        maxLen = max(maxLen, solve(s, 'a', 'c'));
        maxLen = max(maxLen, solve(s, 'b', 'c'));

        // case 3
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                cntA++;
            if (s[i] == 'b')
                cntB++;
            if (s[i] == 'c')
                cntC++;

            if (cntA == cntB && cntA == cntC)
                maxLen = max(maxLen, cntA + cntB + cntC);
            
            string key = to_string(cntA - cntB) + "_" + to_string(cntA - cntC);
            if (mpp.count(key)) {
                maxLen = max(maxLen, i - mpp[key]);
            } else {
                mpp[key] = i;
            }
        }
        return maxLen;
    }
};
