// Approach 1 using recusion with memorization
// TC = O(N^2)
// SC = O(N)
class Solution {
    int t[101][101];
public:
    bool solve(string &s, int i, int cnt) {
        if (cnt < 0) return false;

        if (t[i][cnt] != -1) 
            return t[i][cnt];

        if (i == s.length()) return t[i][cnt] = (cnt == 0);

        if (s[i] == '(') 
            return t[i][cnt] = (solve(s, i + 1, cnt + 1));
        if (s[i] == ')')
            return t[i][cnt] = solve(s, i + 1, cnt - 1);
        return t[i][cnt] = (solve(s, i + 1, cnt) || solve(s, i + 1, cnt + 1) || solve(s, i + 1, cnt - 1));
    }

    bool checkValidString(string s) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, 0);
    }
};

// Approach 2
// TC = O(N)
// SC = O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                mini += 1;
                maxi += 1;
            } else if (s[i] == ')') {
                mini -= 1;
                maxi -= 1;
            } else {
                mini -= 1;
                maxi += 1;
            }
            if (mini < 0) mini = 0;
            if (maxi < 0) return false;
        }
        return mini == 0;
    }
};
