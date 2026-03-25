// Approach 1
// TC = O(K) => K is no. of set bits
// SC = O(1)
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n != 0) {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
};
