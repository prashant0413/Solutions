// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.length();
        vector<vector<char>> c(numRows);
        int i = 0;
        int d = 1;
        for (int j = 0; j < n; j++) {
            c[i].push_back(s[j]);
            if (i == 0) {
                d = 1;
            } else if (i == numRows - 1) {
                d = -1;
            }
            i += d;
        }
        string ans;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < c[i].size(); j++) {
                ans += c[i][j];
            }
        }
        return ans;
    }
};
