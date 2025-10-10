class Solution
{
    int getMinFreq(int freq[])
    {
        int minFreq = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
                minFreq = min(minFreq, freq[i]);
        }
        return minFreq;
    }
    int getMaxFreq(int freq[])
    {
        int maxFreq = 0;
        for (int i = 0; i < 26; i++)
        {
            maxFreq = max(maxFreq, freq[i]);
        }
        return maxFreq;
    }

public:
    int beautySum(string s)
    {
        int n = s.length();
        if (n <= 1)
            return 0;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int freq[26] = {0};
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                int beauty = getMaxFreq(freq) - getMinFreq(freq);
                sum += beauty;
            }
        }
        return sum;
    }
};
