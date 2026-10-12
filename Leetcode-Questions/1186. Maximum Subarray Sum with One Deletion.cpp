// APPROACH 1
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int power = 0;
        int noPower = arr[0];
        int result = arr[0];
        for (int i = 1; i < n; i++) {
            power = max(power + arr[i], noPower);
            noPower = max(arr[i], noPower + arr[i]);
            result = max(result, max(power, noPower));
        }

        return result;
    }
}; 
