// APPROACH 1: RECURSION
// TC: O(LOG N)
// SC: O(LOG N)
class Solution {
  public:
    bool solve(int n, int i) {
        if (n < i) return true;
        if (n % i == 0) return false;
        return solve(n - n / i, i + 1);
    }
  
    bool isLucky(int n) {
        return solve(n, 2);
    }
};
