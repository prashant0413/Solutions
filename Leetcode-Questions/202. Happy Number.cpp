// APPROACH 1
// TC: O(N LOG N)
// SC: O(LOG N)
class Solution {
public:
    bool isHappy(int n) {
        if (n == 1 || n == 7) return true;
        if (n < 10) return false;
        long long sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return isHappy(sum);
    }
};
