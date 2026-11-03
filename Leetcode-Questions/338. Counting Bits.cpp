// APPROACH 1: USING BUILTIN POPCOUNT 
// TC: O(N)
// Sc: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            arr[i] = __builtin_popcount(i);
        }
        return arr;
    }
};

// APPROACH 2: USING OWN BIN COUNT METHOD
// TC: O(N LOG N)
// SC: O(1)
class Solution {
public:
    int solve(int n) {
        int cnt = 0;
        while (n != 0) {
            if (n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            ans[i] = solve(i);
        }
        return ans;
    }
};
