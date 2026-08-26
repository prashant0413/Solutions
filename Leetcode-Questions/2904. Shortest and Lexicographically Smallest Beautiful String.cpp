// Approach 1 brute force
// TC = O(n^3)
// SC = O(n)
class Solution {
public:
    int countOne(string &s) {
        int cnt = 0;
        for (char &c: s) {
            if (c == '1')
                cnt++;
        }
        return cnt;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        for (int len = k; len <= n; len++) {
            string result = "";
            for (int i = 0; i <= n - k; i++) {
                string temp = s.substr(i, len);
                if (countOne(temp) == k) {
                    if (result.empty() || temp < result) {
                        result = temp;
                    }
                }
            }

            if (!result.empty()) {
                return result;
            }
        }
        return "";
    }
};
