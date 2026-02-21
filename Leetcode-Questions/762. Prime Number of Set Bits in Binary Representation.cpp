// Approach 1
// TC = O(right - left + 1)
// SC = O(1)
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            int x = __builtin_popcount(i);
            if (isPrime(x))
                cnt++;
        }
        return cnt;
    }
};
