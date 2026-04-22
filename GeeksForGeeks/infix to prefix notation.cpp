// TC = O(3n)
// SC = O(n)
class Solution {
    bool isOperator(char c) {
        if (c >= 'a' and c <= 'z' || c >= 'A' and c <= 'Z' || c >= '0' and c <= '9')
        return true;
        return false;
    }
    
    int priority(char c) {
        if (c == '^')
        return 3;
        if (c == '*' || c == '/')
        return 2;
        if (c == '+' || c == '-')
        return 1;
        return -1;
    }
    
public:
    string infixToPrefix(string s) {
        int n = s.length();
        reverse(begin(s), end(s));
        string ans = "";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (isOperator(s[i])) {
                ans += s[i];
            } else if (s[i] == ')') {
                st.push(')');
            } else if (s[i] == '(') {
                while (!st.empty() and st.top() != ')') {
                    ans += st.top(); st.pop();
                }
                st.pop();
            } else if (s[i] == '^') {
                while (!st.empty() and priority(s[i]) <= priority(st.top())) {
                    ans += st.top(); st.pop();
                }
                st.push(s[i]);
            } else {
                while (!st.empty() and priority(s[i]) < priority(st.top())) {
                    ans += st.top(); st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            ans += st.top(); st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
