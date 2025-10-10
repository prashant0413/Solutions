class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int idx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + idx, s.begin() + i);
                idx = i + 1;
            }
            if (i == s.length() - 1)
            {
                reverse(s.begin() + idx, s.begin() + i + 1);
            }
        }
        int k = 0;
        char last = ' ';
        for (int i = 0; i < s.length(); i++)
        {
            if (last == ' ' && last == s[i])
                continue;
            s[k++] = s[i];
            last = s[i];
        }
        if (s[k - 1] == ' ')
            k--;
        s.resize(k);
        return s;
    }
};
