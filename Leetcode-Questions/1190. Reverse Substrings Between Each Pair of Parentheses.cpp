// APPROACH 1: BRUTE FORCE
// TC: O(N^2)
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

// APPROACH 2: WORMHOLE TELEPORTATION
// TC: O(N)
// SC: O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> open;
        unordered_map<int, int> door;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                int j = open.top(); open.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        string res;
        int flag = 1;
        for (int i = 0; i < n; i += flag) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                flag = -flag;
            } else {
                res.push_back(s[i]);
            }
        }

        return res;
    }

};
