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
    long long findSum(vector<int> &arr)
    {
        long long sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
    int calculateDays(vector<int> &arr, int mid)
    {
        int days = 1;
        int pack = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] + pack > mid)
            {
                days++;
                pack = arr[i];
            }
            else
            {
                pack += arr[i];
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = findMax(weights);
        int high = findSum(weights);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (calculateDays(weights, mid) <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
