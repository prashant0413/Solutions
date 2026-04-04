// Approach 1
// TC = O(n)
// SC = O(n)
class Solution {
public:
    int t[46];

    Solution() {
        memset(t, -1, sizeof(t));
    }

    int climbStairs(int n) {
        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        if (t[n] != -1) {
            return t[n];
        }

        int res = 0;
        res += climbStairs(n - 1);
        res += climbStairs(n - 2);

        return t[n] = res;
    }
};

// Approach 2
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int prev1 = 1; // ways to reach step 1
        int prev2 = 2; // ways to reach step 2

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};
