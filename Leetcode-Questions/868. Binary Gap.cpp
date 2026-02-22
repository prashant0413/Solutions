// Approach 1
// TC = O(log(N))
// SC = O(1)
class Solution {
public:
    int binaryGap(int n) {
        int cur = 0;
        int prev = -1;
        int result = 0;
        while (n != 0) {
            if (n & 1) {
                result = (prev != -1) ? max(result, cur - prev) : result;
                prev = cur;
            }
            cur++;
            n >>= 1;
        }
        return result;
    }
};

// Approach 2
// TC = O(1)
// SC = O(1)
class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                result = (prev != -1) ? max(result, i - prev) : result;
                prev = i;
            }
        }
        return result;
    }
};
