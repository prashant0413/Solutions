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
    int calculateHours(vector<int> &arr, int hour)
    {
        int totalHours = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totalHours += ceil((double)arr[i] / (double)hour);
        }
        return totalHours;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = findMax(piles);
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int hours = calculateHours(piles, mid);
            if (hours <= h)
            {
                ans = min(ans, mid);
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
