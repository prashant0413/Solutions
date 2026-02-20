// Approach 1
// TC = O(N^3)
// SC = O(1)
class Solution {
public:
    bool isPalindrome(string &s, int i , int j) {
        if (i >= j)
            return true;

        if (s[i] != s[j])
            return false;
        return isPalindrome(s, i + 1, j - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int st = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {;
                if (isPalindrome(s, i, j)) {
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        st = i;
                    }
                }
            }
        }
        return s.substr(st, maxLen);
    }
};

// Same apporach as above with memorization
class Solution {
public:
    int t[1001][1001];
    bool isPalindrome(string &s, int i , int j) {
        if (i >= j)
            return 1;

        if (t[i][j] != -1) {
            return t[i][j];
        }    

        if (s[i] != s[j])
            return t[i][j] = 0;
        return t[i][j] = isPalindrome(s, i + 1, j - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int maxLen = INT_MIN;
        int st = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {;
                if (isPalindrome(s, i, j)) {
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        st = i;
                    }
                }
            }
        }
        return s.substr(st, maxLen);
    }
};

// Approach 2
// TC = O(n * n)
// SC = O(n * n)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1;
        int idx = 0;

        vector<vector<bool>> t(n, vector<bool>(n));

        // t[0][0] = true, t[1][1] = true
        for (int i = 0; i < n; i++)
            t[i][i] = true;

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxLen = 2;
                    idx = i;
                } else if (s[i] == s[j] && t[i + 1][j - 1]) {
                    t[i][j] = true;
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        idx = i;
                    } 
                } else {
                    t[i][j] = false;
                }
            }
        }
        
        return s.substr(idx, maxLen);
    }
};



class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n <= 1)
            return s;

        auto expandFromCenter = [&](int left, int right)
        {
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            return s.substr(left + 1, right - (left + 1));
        };
        string maxStr = s.substr(0, 1);
        for (int i = 0; i < n; i++)
        {
            string odd = expandFromCenter(i, i);
            string even = expandFromCenter(i, i + 1);

            if (odd.length() > maxStr.length())
                maxStr = odd;

            if (even.length() > maxStr.length())
                maxStr = even;
        }
        return maxStr;
    }
};
