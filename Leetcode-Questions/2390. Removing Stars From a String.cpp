// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string res;
        for (char &c: s) {
            if (c != '*') {
                res.push_back(c);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};
