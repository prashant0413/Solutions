// APPROACH 1: TWO POINTER
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int area = min(arr[i], arr[j]) * (j - i);
            maxi = max(area, maxi);
            if (arr[i] >= arr[j]) j--;
            else i++;
        }

        return maxi;
    }
};
