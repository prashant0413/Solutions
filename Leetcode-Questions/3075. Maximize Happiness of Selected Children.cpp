// Approach 1
// TC = O(nlog(n)) + O(k)
// SC = O(1)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long maxi = 0;
        for (int i = 0; i < k; i++) {
            maxi += ((happiness[i] - i) < 0) ? 0 : happiness[i] - i;
        }
        return maxi;
    }
};
