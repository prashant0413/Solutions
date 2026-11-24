// APPROACH 1: BRUTE FORCE
// TC: O(N^2 LOG N)
// SC: O(1)
class Solution {
    int gcd(int a, int b) {
        if (b < a) return gcd(b, a);
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int mod = 1e9;
        for (int i = 0; i < n; i++) {
            long long prod = 1LL;
            long long l = 1;
            long long g = 0;
            for (int j = i; j < n; j++) {
                prod = (prod * 1LL * nums[j]) % mod;
                l = lcm(l, nums[j]) % mod;
                g = gcd(g, nums[j]) % mod;
                if (prod == l * g) maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
