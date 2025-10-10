class Solution
{
    int findMax(vector<vector<int>> &mat, int m, int n, int row)
    {
        int maxi = INT_MIN;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[row][i] > maxi)
            {
                maxi = mat[row][i];
                idx = i;
            }
        }
        return idx;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int i = findMax(mat, m, n, mid);
            int up = (mid - 1 >= 0) ? mat[mid - 1][i] : -1;
            int down = (mid + 1 < m) ? mat[mid + 1][i] : -1;
            if (mat[mid][i] > up && mat[mid][i] > down)
                return {mid, i};
            if (mat[mid][i] < up)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};
