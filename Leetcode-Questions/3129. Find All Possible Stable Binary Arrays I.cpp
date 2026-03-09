// Approach 1
// TC = O(one * zero * limit)
// SC = O(one * zero)
class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int oneLeft, int zeroLeft, bool lastWasOne, int limit) {
        if (zeroLeft == 0 && oneLeft == 0)
            return 1;

        if (t[oneLeft][zeroLeft][lastWasOne] != -1) {
            return t[oneLeft][zeroLeft][lastWasOne];
        }

        int result = 0;
        if (lastWasOne) {
            for (int len = 1; len <= min(limit, zeroLeft); len++) {
                result = (result + solve(oneLeft, zeroLeft - len, false, limit)) % M;
            }
        } else {
            for (int len = 1; len <= min(limit, oneLeft); len++) {
                result = (result + solve(oneLeft - len, zeroLeft, true, limit)) % M;
            }            
        }

        return t[oneLeft][zeroLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;
    }
};
