// APPROACH 1
// TC: O(N LOG N)
// SC: O(1)
class Solution {
  public:
    bool solve(int n) {
        if (n == 1 || n == 7) return true;
        if (n < 10) return false;
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return solve(sum);
    }
    
    int nextHappy(int n) {
        n = n + 1;
        while (true) {
            if (solve(n)) return n;
            n++;
        }
        return -1;
    }
};
