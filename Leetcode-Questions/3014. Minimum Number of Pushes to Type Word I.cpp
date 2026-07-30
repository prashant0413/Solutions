// Approach 1
// TC = O(log(n))
// SC = O(1)
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if (n <= 8) return n;
        int cnt = 0;
        int times = 1;
        while (n > 8) {
            cnt += (8 * times);
            times++;
            n -= 8;
        }
        if (n) {
            cnt += (n * times);
        }
        return cnt;
    }
};
