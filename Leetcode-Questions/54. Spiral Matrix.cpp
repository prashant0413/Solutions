// APPROACH 1
// TC: O(M + N)
// SC: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;
        int top, bottom, left, right;
        top = left = 0;
        bottom = m - 1;
        right = n - 1;

        while (top <= bottom && left <= right) {
            // LEFT TO RIGHT
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // TOP TO BOTTOM
            if (left > right) break;
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // RIGHT TO LEFT
            if (top > bottom) break;
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;

            // BOTTOM TO TOP
            if (left > right) break;
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};
