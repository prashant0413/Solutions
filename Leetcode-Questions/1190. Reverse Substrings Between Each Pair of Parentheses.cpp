// APPROACH 1: BRUTE FORCE
// TC: O(N)
// SC: O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                string str = "";
                while (st.top() != '(') {
                    str.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for (char c: str) {
                    st.push(c);
                }
            } else {
                st.push(s[i]);
            }
        }

        string str;
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(begin(str), end(str));
        return str;
    }
};
