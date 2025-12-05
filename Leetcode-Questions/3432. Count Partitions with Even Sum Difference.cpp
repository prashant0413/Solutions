// Approach 1
// TC = O(n ^ 2)
// SC = O(1)
class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            long long sum2 = 0;
            for (int j = i + 1; j < n; j++)
            {
                sum2 += nums[j];
            }
            if (sum > 0 && sum2 > 0 && (abs(sum - sum2) & 1) != 1)
                cnt++;
        }
        return cnt;
    }
};


// Approach 2
// TC = O(2n)
// SC = O(n)
class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        vector<long long> sufSum(n, 0);
        for (int i = n - 1; i >= 0; i--)
            sufSum[i] = (i < n - 1) ? sufSum[i + 1] + nums[i] : nums[i];

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i < n - 1 && (abs(sum - sufSum[i + 1]) & 1) != 1)
                cnt++;
        }
        return cnt;
    }
};

// Approach 3
// TC = O(2n)
// Sc = O(1)
class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        long long sum = 0;
        for (int i : nums)
            sum += i;

        long long left = 0;
        for (int i = 0; i < n - 1; i++) {
            left += nums[i];
            long long right = sum - left;
            if ((abs(left - right) & 1) != 1)
                cnt++;
        }
        return cnt;
    }
};

// Approach 4
// TC = O(n)
// SC = O(1)
class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        long long sum = 0;
        for (int i : nums)
            sum += i;
        return (sum & 1) == 1 ? 0 : n - 1;
    }
};
