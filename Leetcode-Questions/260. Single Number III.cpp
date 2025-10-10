class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XOR = 0;
        for (auto i : nums)
            XOR ^= i;

        int rightMost = (XOR & (XOR - 1)) ^ XOR;
        int b1 = 0;
        int b2 = 0;
        for (auto i : nums) {
            if (rightMost & i)
                b1 ^= i;
            else
                b2 ^= i;
        }
        return {b1, b2};
    }
};
