class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        int i;
        int n = 0;
        for (i = 1; i <= k; i++) {
            n = (n * 10 + 1) % k;
            if (n == 0)
                break;
        }
        return i;
    }
};
