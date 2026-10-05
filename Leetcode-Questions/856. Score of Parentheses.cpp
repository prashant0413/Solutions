// APPROACH 1: USING STACK
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        stack<int> st;

        int score = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(score);
                score = 0;
            } else  {
                if (s[i - 1] == '(') {
                    score = st.top() + 1;
                } else {
                    score = (2 * score) + st.top();
                }
                st.pop();
            }
        }

        return score;
    }
};


// APPROACH 2: USING DEPTH 
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        int score = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
            } else {
                cnt--;
                if (s[i - 1] == '(')
                    score += (1 << cnt);
            }
        }

        return score;
    }
};
