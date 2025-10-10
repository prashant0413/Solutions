class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                if (s[i] == ')') {
                    char c = st.top();
                    if (char(s[i] - 1) != c)
                        return false;
                    else 
                        st.pop();
                } else {
                    char c = st.top();
                    if (char(s[i] - 2) != c)
                        return false;
                    else 
                        st.pop();                    
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};
