// Approach 1
// TC = O(max(n1, n2))
// SC = O(n)
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }

            int rem = sum % 10 + '0';
            ans += (char)rem;
            carry = sum / 10;
        }
        if (carry) {
            ans += (char)(carry + '0');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
