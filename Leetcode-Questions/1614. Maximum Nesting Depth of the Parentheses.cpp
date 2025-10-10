class Solution
{
public:
    int maxDepth(string s)
    {
        int maxCnt = 0;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                cnt++;
                maxCnt = max(cnt, maxCnt);
            }
            if (s[i] == ')')
            {
                cnt--;
            }
        }
        return maxCnt;
    }
};
