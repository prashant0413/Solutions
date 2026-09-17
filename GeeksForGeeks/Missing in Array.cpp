// APPROACH 1
// TC: O(N)
// SC: O(1)
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int x = 0;
        for (int i = 1; i <= arr.size() + 1; i++) {
            x ^= i;
        }
        
        for (int i: arr)
            x ^= i;
            
        return x;
    }
};
