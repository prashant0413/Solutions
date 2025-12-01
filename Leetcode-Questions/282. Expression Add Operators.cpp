// Approach 1
// TC = O(4 ^ n)
// SC = O(n)
class Solution {
public:
    vector<string> ans;

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, "", 0, 0);
        return ans;
    }

    void solve(string s, int target, int i, string path, long eval, long residual) {
        if (i >= s.length()) {
            if (eval == target) {
                ans.push_back(path);
            }
            return;
        }

        long num = 0;
        string curr = "";
        for (int j = i; j < s.length(); j++) {
            if (j > i && s[i] == '0')
                return;
            curr += s[j];
            num = num * 10 + s[j] - '0';
            if (i == 0) {
                solve(s, target, j + 1, path + curr, num, num);
            } else {
                solve(s, target, j + 1, path + '+' + curr, eval + num, num);
                solve(s, target, j + 1, path + '-' + curr, eval - num, -num);
                solve(s, target, j + 1, path + '*' + curr, eval - residual + num * residual, residual * num);
            }
        }
    }
};
