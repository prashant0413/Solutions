// APPROACH 1:
// TC: O(N)
// SC: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            digits[i] = digits[i] + 1;
            if (digits[i] <= 9) return digits;
            digits[i] = 0;
        }
        vector<int> res(n + 1, 0);
        res[0] = 1;
        return res;
    }
};
