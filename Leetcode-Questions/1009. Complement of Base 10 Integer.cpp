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
