// Approach 1
// TC = O(w) + O(n)
// SC = O(n)
class Solution {
    bool isOperand(char c) {
        if (c >= 'a' and c <= 'z' || c >= 'A' and c <= 'Z' || c >= '0' and c <= '9')
            return true;
        return false;
    }
    
  public:
    string postToInfix(string &s) {
        stack<string> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isOperand(s[i]))
                st.push(string(1, s[i]));
            else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string con = "(" + t2 + s[i] + t1 + ")";
                st.push(con);
            }
        }
        return st.top();
    }
};
