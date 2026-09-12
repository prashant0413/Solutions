// Approach 1
// TC: O(n log n)
// SC: O(1) 
class Solution {
  public:
    int solve(vector<int>& bt) {
        int n = bt.size();
        sort(begin(bt), end(bt));
        
        int t = 0;
        int wt = 0;
        for (int i = 0; i < n; i++) {
            wt += t;
            t += bt[i];
        }
        
        return wt / n;
    }
};
