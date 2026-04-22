// Approach 1
// TC = O(n) + O(w)
// SC = O(n)
class Solution {
    bool isOperand(char c) {
        if (c >= 'A' and c <= 'Z' || c >= 'a' and c <= 'z' || c >= '0' and c <= '9')
            return true;
        return false;
    }
  public:
    string postToPre(string s) {
        int n = s.length();
        stack<string> st;
        for (int i = 0; i < n; i++) {
            if (isOperand(s[i])) {
                st.push(string(1, s[i]));
            } else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string con = s[i] + t2 + t1;
                st.push(con);
            }
        }
        return st.top();
    }
};
