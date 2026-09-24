// APPROACH 1
// TC: O(SQRT(N))
// SC: O(1)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int n = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                if (i != num)
                    n += i;
                if (num / i != num) {
                    n += num / i;
                }
            }
        }
        return n == num;
    }
};
