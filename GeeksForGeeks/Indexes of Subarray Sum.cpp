// APPROACH 1 USING SET
// TC: O(N)
// sc: O(N)
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        mpp[0] = 0;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (mpp.count(sum - target)) {
                int st = mpp[sum - target] + 1;
                int en = i + 1;
                return {st, en};
            }
            
            if (mpp.count(sum) == 0)
                mpp[sum] = i + 1;
        }
        
        return {-1};
    }
};
