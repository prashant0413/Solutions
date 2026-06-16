// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for (char &c: s) {
            if (c >= 'a' && c <= 'z') {
                ans.push_back(c);
            } else if (c == '*' && ans.size() > 0) {
                ans.pop_back();
            } else if (c == '#') {
                ans += ans;
            } else if (c == '%') {
                reverse(begin(ans), end(ans));
            }
        }
        return ans;
    }
};
