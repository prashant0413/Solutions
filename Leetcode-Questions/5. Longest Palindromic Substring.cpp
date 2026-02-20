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
