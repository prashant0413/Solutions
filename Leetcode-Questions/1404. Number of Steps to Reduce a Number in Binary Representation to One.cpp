// Approach 1
// TC = O(N*N)
// SC = O(1)
class Solution {
public:
    void addOne(string &s) {
        int i = s.length() - 1;
        while ( i >= 0 && s[i] != '0') {
            s[i] = '0';
            i--;
        }
        if (i < 0)
            s = '1' + s;
        else
            s[i] = '1';
    } 

    int numSteps(string s) {
        int cnt = 0;
        while (s.length() > 1) {
            int n = s.length();
            if (s[n - 1] ==  '0') {
                s.pop_back();
            } else {
                addOne(s);
            }
            cnt++;
        }
        return cnt;
    }
};

// Approach 2
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        int carry = 0;
        for (int i = s.length() - 1; i >= 1; i--) {
            if (((s[i] - '0') + carry) & 1) {
                carry = 1;
                cnt += 2;
            } else {
                cnt += 1;
            }
        }
        return cnt + carry;
    }
};
