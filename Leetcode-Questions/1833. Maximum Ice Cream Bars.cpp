// Approach 1
// TC = O(N*log(N))
// SC = O(1)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int cnt = 0;
        for (int &i: costs) {
            if (coins < i) return cnt;
            coins -= i;
            cnt++;
        }
        return cnt;
    }
};
