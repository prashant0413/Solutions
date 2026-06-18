// Approach 1
// TC = O(1)
// SC = O(1)
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAgle = minutes * 6.0;
        double hourAgle = hour * 30.0;
        double result = abs(minAgle - hourAgle - minutes * 0.5);
        if (result <= 180.0)
            return result;
        return 360.0 - result;
    }
};
