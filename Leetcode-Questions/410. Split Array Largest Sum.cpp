#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int cntSubarray(vector<int> &nums, int mid)
    {
        int cntsub = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] <= mid)
            {
                sum += nums[i];
            }
            else
            {
                cntsub++;
                sum = nums[i];
            }
        }
        return cntsub;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (cntSubarray(nums, mid) <= k)
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

int main()
{
    Solution s;
    vector<int> arr = {7, 2, 5, 10, 8};
    cout << s.splitArray(arr, 2) << endl;
    return 0;
}
