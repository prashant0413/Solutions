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

// Approach 2
// TC = O(right−left+1)
// SC = O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        vector<bool> isPrime(33, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 32; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 32; j += i) 
                    isPrime[j] = false;
            }
        }
        for (int i = left; i <= right; i++) {
            int x = __builtin_popcount(i);
            if (isPrime[x])
                cnt++;
        }
        return cnt;
    }
};
