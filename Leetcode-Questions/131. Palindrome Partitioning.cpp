// APPROACH 1: BACKTRACKING 
// TC: O(N . 2^N)
// SC: O(N)
class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false; l++; r--;
        }
        return true;
    }

    void solve(int idx, string &s, vector<string> &temp, vector<vector<string>> &res) {
        if (idx >= s.length()) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, temp, res);
                temp.pop_back();                 
            }
        }
    } 

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(0, s, temp, res);
        return res;
    }
};
