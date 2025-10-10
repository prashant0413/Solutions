class Solution
{
    int findMax(vector<int> &arr)
    {
        int maxi = arr[0];
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
    long long calculateFlower(vector<int> &arr, int mid, int k)
    {
        long long totalFlower = 0;
        long long flr = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= mid)
            {
                totalFlower++;
                if (totalFlower == k)
                {
                    flr++;
                    totalFlower = 0;
                }
            }
            else
                totalFlower = 0;
        }
        return flr;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        long long total = (long long)m * k;
        if (total > n)
            return -1;

        int low = 1;
        int high = findMax(bloomDay);
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long flower = calculateFlower(bloomDay, mid, k);
            if (flower >= m)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
