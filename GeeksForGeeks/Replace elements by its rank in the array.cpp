// Approach 1
// TC = O(nlog(n)) + O(2n)
// SC = O(2n)
class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> t(arr.begin(), arr.end());
        sort(t.begin(), t.end());
        unordered_map<int, int> mpp;
        int rank = 1;
        for (int i = 0; i < N; i++) {
            if (mpp.find(t[i]) != mpp.end())
                continue;
            mpp[t[i]] = rank++;
        }
                
        for (int i = 0; i < N; i++) {
            arr[i] = mpp[arr[i]];
        }
        
        return arr;
    }
};
