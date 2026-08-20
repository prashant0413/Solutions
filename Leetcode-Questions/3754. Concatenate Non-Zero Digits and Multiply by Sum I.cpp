// Approach 1
// TC = O(log(n))
// SC = O(1)
class Solution {
    long long sum = 0;
public:
    long long getDigits(int n) {
        long long num = 0;
        while (n != 0) {
            int rem = n % 10;
            if (rem != 0) {
                num = num * 10 + rem;
                sum += rem;
            }
            n /= 10;
        }

        long long rev = 0;
        while (num != 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }

        return rev;
    }

    long long sumAndMultiply(int n) {
        return getDigits(n) * sum;
    }
};
