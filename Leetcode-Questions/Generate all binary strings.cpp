// User function Template for C++

class Solution {
    void solve(int num, int i, string s,vector<string> &result,bool flag) {
        if (i >= num) {
            result.push_back(s);
            return;
        }
        s[i] = '0';
        solve(num, i+1, s, result, true);
        if (flag == true) {
            s[i] = '1';
            solve(num, i+1, s, result, false);
            s[i] = '0';
        }
    }
public:
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> result;
        string s(num, '0');
        solve(num, 0, s, result, true);
        return result;
    }
};
