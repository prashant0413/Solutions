// Approach 1
// TC = O(1)
// SC = O(1)
class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        long long cnt = 0;
        if (n >= (long long)1e15) {
            long long digits = n - (long long)1e15 + 1;
            cnt += digits * 5;
            n -= digits;
        } 
        if (n >= 1e12) {
            long long digits = n - (long long)1e12 + 1;
            cnt += digits * 4;
            n -= digits;
        }
        if (n >= 1e9) {
            long long digits = n - (long long)1e9 + 1;
            cnt += digits * 3;
            n -= digits;
        }
        if (n >= 1e6) {
            long long digits = n - (long long)1e6 + 1;
            cnt += digits * 2;
            n -= digits;
        }
        if (n >= 1000) {
            long long digits = n - (long long)1e3 + 1;
            cnt += digits * 1;
            n -= digits;
        }
        return cnt;
    }
};

// Same code but better readability
class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;

        long long cnt = 0;
        long long bound = 1e15;
        int commas = 5;

        while (n >= 1000) {
            if (n >= bound) {
                long long digits = n - bound + 1;
                cnt += digits * commas;
                n -= digits;
            }
            bound = bound / 1e3;
            commas -= 1;
        }

        return cnt;
    }
};
