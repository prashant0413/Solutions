// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        int dash = 0;
        for (char &c: moves) {
            if (c == 'L')
                left++;
            if (c == 'R')
                right++;
            if (c == '_')
                dash++;
        }
        if (left >= right)
            return (left - right) + dash;
        return (right - left) + dash;
    }
};
