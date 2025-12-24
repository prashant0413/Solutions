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
