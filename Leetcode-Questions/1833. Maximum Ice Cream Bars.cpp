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

// Approach 2
// TC = O(n + k)
// SC = O(k)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = *max_element(begin(costs), end(costs));
        vector<int> freq(maxi + 1, 0);
        for (int &i: costs) {
            freq[i]++;
        }
        int cnt = 0;
        for (int i = 1; i <= maxi; i++) {
            if (freq[i] == 0) continue;
            if (coins < i) return cnt;
            int buy = min(freq[i], coins / i);
            cnt += buy;
            coins -= buy * i;
        }
        return cnt;
    }
};
