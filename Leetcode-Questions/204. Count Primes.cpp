// TC = O(N LOG(LOG N))
// SC = O(N + 1)


class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1, 1);
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i] == 1) {
                cnt++;
                for (long long j = (long long)i * i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};
