// Approach 1
// TC = O(n ^ 2)
// SC = O(1)
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
    	int maxPro = INT_MIN;
    	for (int i = 0; i < n; i++) {
    		int pro = 1;
    		for (int j = i; j < n; j++) {
    			pro *= arr[j];
    			maxPro = max(maxPro, pro);
    		}
    	}
    	return maxPro;
    }
};

// Approach 2
// TC = O(n)
// SC = O(1)
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int pre = 1;
        int suf = 1;
        int maxPro = INT_MIN;
        for (int i = 0; i < n; i++)  {
            pre *= arr[i];
            suf *= arr[n - 1 - i];
            
            maxPro = max(maxPro, max(pre, suf));
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;
        }
        return maxPro;
    }
};
