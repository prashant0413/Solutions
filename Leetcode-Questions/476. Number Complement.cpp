// Approach 1
// TC = O(1)
// SC = O(1)
class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;
        long long mask = (1LL << ((long long)log2(num) + 1)) - 1;
        return mask ^ num;
    }
};
