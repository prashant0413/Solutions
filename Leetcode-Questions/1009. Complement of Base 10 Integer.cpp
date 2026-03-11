// Appproach 1
// TC = O(log(N))
// SC = O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int ans = 0;
        for (int i = log2(n); i >= 0; i--) {
            ans = ans << 1;
            int isOn =  1 & (n >> i);
            ans = ans | (1 - isOn);
        }
        return ans;
    }
};

// Apporch 2
// TC = O(log(n))
// SC = O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int mask = 0;
        while (mask < n) {
            mask <<= 1;
            mask |= 1;
        }

        return mask ^ n;
    }
};

// Approach 3
// TC = O(1)
// SC = O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int mask = (1 << ((int)log2(n) + 1)) - 1;
        return n ^ mask;
    }
};
