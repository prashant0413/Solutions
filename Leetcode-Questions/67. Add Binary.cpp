// Approach
// TC = O(n)
// SC = O(1)

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 && j >= 0) {
            if (carry + (a[i] - '0') + (b[j] - '0') == 3) {
                ans += '1';
                carry = 1;
                i--;
                j--;   
            } else if (carry + (a[i] - '0') + (b[j] - '0') == 2) {
                ans += '0';
                carry = 1;
                i--;
                j--;
            } else if (carry + (a[i] - '0') + (b[j] - '0') == 1) {
                ans += '1';
                carry = 0;
                i--;
                j--;
            } else {
                ans += '0';
                carry = 0;
                i--;
                j--;
            }
        }
        while (i >= 0) {
            if (carry + (a[i] - '0') == 2) {
                ans += '0';
                carry = 1;
            } else if (carry + (a[i] - '0') == 1) {
                ans += '1';
                carry = 0;
            } else {
                ans += '0';
                carry = 0;
            }
            i--;
        }
        while (j >= 0) {
            if (carry + (b[j] - '0') == 2) {
                ans += '0';
                carry = 1;
            } else if (carry + (b[j] - '0') == 1) {
                ans += '1';
                carry = 0;
            } else {
                ans += '0';
                carry = 0;
            }
            j--;
        }
        if (carry) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
