// Approach 1
// TC = O(n + log(max(a, b)))
// SC = O(1)
class Solution {
public:
    int hcf(int a, int b) {
        if (a > b) return hcf(b, a);
        while (b % a != 0) {
            int t = a;
            a = b % a;
            b = t;
        }
        return a;
    }

    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        for (int i = 1; i <= n; i++) {
            sumEven += (2 * i);
            sumOdd += (2 * i - 1);
        }
        return hcf(sumEven, sumOdd);
    }
};
