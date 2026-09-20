// APPROACH 1: BRUTE FORCE
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            int pro = (26 - (s[i] - 'a')) * (i + 1);
            sum += pro;
        }
        return sum;
    }
};
