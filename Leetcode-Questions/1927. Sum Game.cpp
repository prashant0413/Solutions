// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int rightKnown = 0;
        int rightQmarks = 0;

        int leftKnown = 0;
        int leftQmarks = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') {
                    leftQmarks++;
                } else {
                    leftKnown += num[i] - '0';
                }
            } else {
                if (num[i] == '?') {
                    rightQmarks++;
                } else {
                    rightKnown += num[i] - '0';
                }
            }
        }

        if ((leftQmarks + rightQmarks) & 1) {
            return true;
        }

        int LEFT = 2 * leftKnown + 9 * leftQmarks;
        int RIGHT = 2 * rightKnown + 9 * rightQmarks;

        return !(LEFT == RIGHT);
    }
};
