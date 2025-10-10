class Solution {
    double power(double x, long long n, double ans) {
        if (n == 0)
            return ans;
        if (n % 2 == 1) {
            return power(x * x, n / 2, ans * x);
        } else {
            return power(x * x, n / 2, ans);
        }
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            N = -N;
            x = 1 / x;
        }
        return power(x, N, 1.0);
    }
};
