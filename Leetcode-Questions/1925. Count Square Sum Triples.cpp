// Approach 1
// TC = O(n ^ 2 log s)
// SC = O(1)
class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                int s = a * a + b * b;
                int x = sqrt(s);
                if (x * x == s && x <= n)
                    cnt += 2;
            }
        }
        return cnt;
    }
};
