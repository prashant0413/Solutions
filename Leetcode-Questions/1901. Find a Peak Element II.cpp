// Approach 1
// TC = O(nlog(m))
// SC = O(1)

class Solution {
public:
    int maxElement(vector<int> &arr) {
        int idx = 0;
        int ele = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > ele) {
                ele = arr[i];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int col = maxElement(mat[mid]);
            int top = mid > 0 ? mat[mid - 1][col] : -1;
            int down = mid + 1 < m ? mat[mid + 1][col] : -1;
            if (mat[mid][col] > top && mat[mid][col] > down)
                return {mid, col};
            if (mat[mid][col] < top) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};
