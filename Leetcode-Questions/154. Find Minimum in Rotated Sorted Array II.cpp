class Solution {
public:
    int findMin(vector<int> &arr) {
        int low = 0;
        int high = arr.size() - 1;
        while (low < high) {
            int m = (low + high) >> 1;
            if (arr[m] == arr[high]) {
                high--;
            } else if (arr[high] > arr[m]) {
                high = m;
            } else {
                low = m + 1;
            }
        }
        return arr[low];
    }
};
