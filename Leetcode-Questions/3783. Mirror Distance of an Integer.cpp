// Approach 1
// TC = O(log10(N))
// SC = O(1)
class Solution {
public:
    int mirrorDistance(int n) {
        long long org = n;
        long long rev = 0;
        while (n != 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return (int)abs(org - rev);
    }
};
