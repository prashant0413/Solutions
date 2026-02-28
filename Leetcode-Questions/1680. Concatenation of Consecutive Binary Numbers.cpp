// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        long result = 0;
        for (int i = 1; i <= n; i++) {
            int bits = log2(i) + 1;
            result = (((result << bits) % M) + i) % M;
        }
        return result;
    }
};

// Approach 2
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        long result = 0;
        int bits = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                bits++;
            }
            result = (((result << bits) % M) + i) % M;
        }
        return result;
    }
};
