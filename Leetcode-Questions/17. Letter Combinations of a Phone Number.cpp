// APPROACH 1: RECURSIVE
// TC: O(N . 4^N)
// SC: O(N) + 
class Solution {
    int n;
    unordered_map<char, string> mpp;
private:
    void solve(int i, string &digits, vector<string> &ans, string &str) {
        if (i >= n) {
            ans.push_back(str);
            return;
        }

        char d = digits[i];
        for (int j = 0; j < mpp[d].size(); j++) {
            str.push_back(mpp[d][j]);
            solve(i + 1, digits, ans, str);
            str.pop_back();
        } 
    }
public:
    Solution() {
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        n = digits.length();
        vector<string> ans;
        string str = "";
        solve(0, digits, ans, str);
        return ans;
    }
};
