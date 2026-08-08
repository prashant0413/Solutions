// Approach 1
// TC = O(M*LOG(K))
// SC = O(1)
class Solution {
public:
    bool isDivisible(int n, int t) {
        int prod = 1;
        while (n > 0) {
            prod *= (n % 10);
            n /= 10;
        }
        return prod % t == 0 ? true : false;
    }

    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            if (isDivisible(i, t)) {
                return i;
            }
        }
        return 0;
    }
};
