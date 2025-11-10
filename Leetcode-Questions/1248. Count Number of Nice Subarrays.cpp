class Solution
{
    int fun(vector<int> &nums, int k) {
        if (k < 0)
            return 0;

        int l,r;
        l = r = 0;
        int cnt = 0;
        int sum = 0;
        while (r < nums.size()) {
            sum += (nums[r] & 1);
            while (sum > k) {
                sum -= (nums[l] & 1);
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return fun(nums, k) - fun(nums, k - 1);
    }
}; 
