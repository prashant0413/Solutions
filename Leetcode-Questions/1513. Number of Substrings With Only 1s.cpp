class Solution
{
public:
    int m = 1e9 + 7;
    int numSub(string s)
    {
        int n = s.length();
        int cnt = 0;
        int l, r;
        l = r = 0;
        long long sum = 0;
        while (r < n)
        {
            if (sum + (s[r] - '0') > sum)
            {
                cnt = (cnt % m) + (r - l + 1) % m;
                sum += s[r] - '0';
                r++;
            }
            else
            {
                r++;
                l = r;
            }
        }
        return cnt;
    }
};
