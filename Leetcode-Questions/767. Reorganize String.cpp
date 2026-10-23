// APPROACH 1: GREEDY
// TC: O(26 . N)
// SC: O(26)
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int mpp[26] = {0};
        for (char c: s) {
            mpp[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (mpp[i] == 0) continue;
            if (mpp[i] > (n - mpp[i] + 1)) return "";
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            int maxi = -1;
            int idx1 = -1;
            for (int j = 0; j < 26; j++) {
                if (mpp[j] == 0) continue;
                if (maxi < mpp[j]) {
                    maxi = mpp[j];
                    idx1 = j;
                }
            }

            char c;
            if (idx1 != -1) {
                mpp[idx1]--;
                c = idx1 + 'a';
                res.push_back(c);
            }

            int mini = INT_MAX;
            int idx2 = -1;
            for (int j = 0; j < 26; j++) {
                if (mpp[j] == 0 || idx1 == j) continue;
                if (mini > mpp[j]) {
                    mini = mpp[j];
                    idx2 = j;
                }
            }

            if (idx2 != -1) {
                mpp[idx2]--;
                c = idx2 + 'a';
                res.push_back(c);
            }
        }

        return res;
    }
};
