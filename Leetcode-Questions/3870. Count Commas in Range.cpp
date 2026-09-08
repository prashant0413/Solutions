// Approach 1
// TC = O(1)
// SC = O(1)
class Solution {
public:
    int countCommas(int n) {
        return (n - 999 > 0) ? n - 999 : 0;
    }
};
