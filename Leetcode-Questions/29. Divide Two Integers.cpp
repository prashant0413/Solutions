class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        // Handle sign
        bool sign = (dividend >= 0) == (divisor >= 0);

        long long x = dividend;
        long long y = divisor;
        x = (x < 0) ? -x : x;
        y = (y < 0) ? -y : y;

        long long q = 0;
        while (x >= y) {
            int cnt = 0;
            while (x >= (y << (cnt + 1)))
                cnt++;
            q += (1LL << cnt);
            x -= (y << cnt);
        }

        if (!sign) q = -q;

        // Clamp result within 32-bit signed range
        if (q > INT_MAX) return INT_MAX;
        if (q < INT_MIN) return INT_MIN;

        return (int)q;
    }
};
