class Solution {
    vector<string> result;

    void solve(int ix, string &str, string &s, unordered_map<char, string> &mpp) {
        if (ix >= str.length()) {
            result.push_back(s);
            return;
        }

        char ch = str[ix];
        string k = mpp[ch];

        for (int i = 0; i < k.length(); i++) {
            s.push_back(k[i]);
            solve(ix + 1, str, s, mpp);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }

        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        string s = "";

        solve(0, digits, s, mpp);
        return result;
    }
};
