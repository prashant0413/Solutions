// Approach 1
// TC = O(n * 2^n * log(M*k))
// SC = O(1)
class Solution {
public:
    typedef long long L;
    L countSmaller(L mid, vector<int>& coins) {
        L correctCount = 0;
        int n = coins.size();
        for (int expression = 1; expression <= (1 << n) - 1; expression++) {
            L lcm = 0;
            L order = 0;
            for (int i = 0; i < n; i++) {
                if (expression & (1 << i)) {
                    order++;
                    if (lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = (lcm * coins[i]) / gcd(lcm, coins[i]);
                    }
                }
            }
            if (order & 1) {
                correctCount += mid / lcm;
            } else {
                correctCount -= mid / lcm;
            }
        }
        return correctCount;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        L result = -1;
        L l = 1;
        L r = (L)*max_element(begin(coins), end(coins)) * k;
        while (l <= r) {
            L mid = l + (r - l) / 2;
            if (countSmaller(mid, coins) >= k) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};
