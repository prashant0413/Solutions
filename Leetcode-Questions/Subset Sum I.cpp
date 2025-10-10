class Solution {
    vector<int> result;
    
    void solve(int ix, vector<int> &arr, int sum) {
        if (ix == arr.size()) {
            result.push_back(sum);
            return;
        }
        
        solve(ix + 1, arr, sum + arr[ix]);
        solve(ix + 1, arr, sum);
    }
    
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        solve(0, arr, 0);
        return result;
    }
};
