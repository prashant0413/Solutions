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

// Approach 2 using sliding window
// TC = O(n^2)
// SC = O(n)
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int l, r;
        l = r = 0;
        int ones = 0;
        string result = "";
        while (r < n) {
            if (s[r] == '1') {
                ones++;
            }

            while (ones > k || s[l] == '0') {
                if (s[l] == '1')
                    ones--;
                l++;
            }

            if (ones == k) {
                string temp = s.substr(l, r - l + 1);
                if (result.empty() || temp.length() < result.length() || (temp.length() == result.length() && temp < result)) {
                    result = temp;
                }
            }
            r++;
        }
        return result;
    }
};
