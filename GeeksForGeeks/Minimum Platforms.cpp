// Approach 1
// TC = O(2n + 2nlog(n))
// SC = O(1)
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int maxCnt = 0;
        int cnt = 0;
        int i, j;
        i = j = 0;
        while (i < n) {
            if (arr[i] <= dep[j]) {
                cnt++;
                i++;
            } else {
                cnt--;
                j++;
            }
            maxCnt = max(cnt, maxCnt);
        }
        
        return maxCnt;
    }
};
