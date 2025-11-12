class Solution
{
public:
    int minOperations(vector<int> &arr)
    {
        int n = arr.size();
        int cntOne = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
                cntOne++;
        }

        if (cntOne > 0)
            return n - cntOne;

        int minSubarray = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int gcd = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                gcd = __gcd(gcd, arr[j]);
                if (gcd == 1)
                {
                    minSubarray = min(minSubarray, j - i);
                    break;
                }
            }
        }

        if (minSubarray == INT_MAX)
            return -1;
        return minSubarray + (n - 1);
    }
};
