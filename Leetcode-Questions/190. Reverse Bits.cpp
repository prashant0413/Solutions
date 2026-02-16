// Approach 1
// TC = O(32)
// SC = O(1)
class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res = res | (n & 1);
            n >>= 1;
        }
        return res;
    }
};
