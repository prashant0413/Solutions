class Solution
{
    int upperBound(vector<int> &arr, int k)
    {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
    int countSmall(vector<vector<int>> &mat, int mid)
    {
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            cnt += upperBound(mat[i], mid);
        }
        return cnt;
    }

public:
    int median(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n - 1]);
        }
        int req = (m * n) / 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int cnt = countSmall(mat, mid);
            if (cnt <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
