// Approach 1
// TC = O(log(n))
// SC = O(1)
class Solution {
public:
    bool checkDivisibility(int n) {
        long long pro = 1;
        long long sum = 0;
        int org = n;
        while (n != 0) {
            pro *= (n % 10) * 1LL;
            sum += (n % 10);
            n /= 10;
        }
        return org % (sum + pro) == 0;
    }
};
