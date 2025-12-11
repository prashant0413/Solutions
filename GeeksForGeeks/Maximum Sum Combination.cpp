// Approach 1
// TC = O(n^2) + O(2nlog(2n))
// SC = O(2n + k)
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        vector<int> res;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res.push_back(a[i] + b[j]);
            }
        }
        sort(res.begin(), res.end(), greater<int>());
        vector<int> ans(res.begin(), res.begin() + k);
        return ans;
    }
};
