class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.length();
        unordered_map<char, int> mpp;
        mpp.clear();
        int l, r;
        l = r = 0;
        int maxLen = -1;
        while (r < n)
        {
            mpp[s[r]] = r;
            if (mpp.size() > k)
            {
                int idx = mpp[s[l]];
                if (idx == l)
                {
                    mpp.erase(s[l]);
                }
                l++;
            }
            if (mpp.size() == k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};
