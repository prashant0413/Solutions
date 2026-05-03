// Approach 1
// TC = O(n1 * n2)
// SC = O(n1 + n2)
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n1 = num1.length();
        int n2 = num2.length();
        string result(n1 + n2, '0');
        int carry = 0;
        int k;
        int power = 0;
        for (int i = n1 - 1; i >= 0; i--) {
            int prod = 0;
            k = n1 + n2 - 1 - power;
            for (int j = n2 - 1; j >= 0; j--) {
                prod = (num1[i] - '0') * (num2[j] - '0') + carry + (result[k] - '0');
                result[k] = (char)(prod % 10 + '0');
                carry = prod / 10;
                k--;
            }
            power++;
            while (carry != 0) {
                int sum = carry + (result[k] - '0');
                result[k] = (char)(sum % 10 + '0');
                carry = sum / 10;
                k--;
            }
        }

        int i = 0;
        while (result[i] == '0') {
            i++;
        }
        result = result.substr(i);
        return result;
    }
};
