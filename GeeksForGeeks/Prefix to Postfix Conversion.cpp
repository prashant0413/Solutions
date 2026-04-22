// Approach 1
// TC = O(w) + O(n)
// SC = O(n)
class Solution {
    bool isOperand(char c) {
        if (c >= 'A' and c <= 'Z' || c >= 'a' and c <= 'z' || c >= '0' and c <= '9')
            return true;
        return false;
    }
  public:
    string preToPost(string s) {
        int n = s.length();
        stack<string> st;
        for (int i = n - 1; i >= 0; i--) {
            if (isOperand(s[i])) {
                st.push(string(1, s[i]));
            } else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string con = t1 + t2 + s[i];
                st.push(con);
            }
        }
        return st.top();
    }
};
