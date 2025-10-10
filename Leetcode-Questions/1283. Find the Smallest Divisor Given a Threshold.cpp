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
    long long sumDivisor(vector<int> &nums, int mid)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += (long long)ceil((double)nums[i] / (double)mid);
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = findMax(nums);
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (sumDivisor(nums, mid) <= threshold)
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
