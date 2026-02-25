// Approach 1
// TC = O(N*LOG(N))
// SC = O(1)
class Solution {
public:
    static bool cmp(int a, int b) {
        if (__builtin_popcount(a) < __builtin_popcount(b))
            return true;
        if (__builtin_popcount(a) == __builtin_popcount(b))
            return a < b;
        return false;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
