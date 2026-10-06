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

// APPROACH 2: USING COUNTERS 
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        for (char c: s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) open--;
                else {
                    close++;
                }
            }
        }

        return open + close;
    }
};
