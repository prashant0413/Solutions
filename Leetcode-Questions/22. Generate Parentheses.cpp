class Solution {
    void solve(int len, int i, int total, vector<string> &result, string &s) {
        if (i >= len) {
            if (total == 0) {
                result.push_back(s);
                return;
            }
        }
        if (total > len - i || total < 0) {
            return;
        }
        s[i] = '(';
        solve(len, i + 1, total + 1, result, s);
        s[i] = ')';
        solve(len, i + 1, total - 1, result, s);
    }
public:
    vector<string> generateParenthesis(int n) {
        string s(n * 2, '0');
        vector<string> result;
        solve(n * 2, 0, 0, result, s);
        return result;
    }
};
