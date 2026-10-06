// APPROACH 1: USING STACK
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();

        stack<char> st;
        for (char c: s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == '(') st.pop();
                else {
                    st.push(c);
                }
            }
        }

        return st.size();
    }
};
