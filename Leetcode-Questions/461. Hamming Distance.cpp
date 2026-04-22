// Approach 1
// TC = O(log(n))
// SC = O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = x ^ y;
        int ans = __builtin_popcount(a);
        return ans;
    }
};
