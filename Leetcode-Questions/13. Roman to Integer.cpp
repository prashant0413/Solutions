class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'M')
            {
                result += 1000;
            }
            else if (i + 1 < s.length() && s[i] == 'C' && s[i + 1] == 'M')
            {
                result += 900;
                i++;
            }
            else if (s[i] == 'D')
            {
                result += 500;
            }
            else if (i + 1 < s.length() && s[i] == 'C' && s[i + 1] == 'D')
            {
                result += 400;
                i++;
            }
            else if (s[i] == 'C')
            {
                result += 100;
            }
            else if (i + 1 < s.length() && s[i] == 'X' && s[i + 1] == 'C')
            {
                result += 90;
                i++;
            }
            else if (s[i] == 'L')
            {
                result += 50;
            }
            else if (i + 1 < s.length() && s[i] == 'X' && s[i + 1] == 'L')
            {
                result += 40;
                i++;
            }
            else if (s[i] == 'X')
            {
                result += 10;
            }
            else if (i + 1 < s.length() && s[i] == 'I' && s[i + 1] == 'X')
            {
                result += 9;
                i++;
            }
            else if (s[i] == 'V')
            {
                result += 5;
            }
            else if (i + 1 < s.length() && s[i] == 'I' && s[i + 1] == 'V')
            {
                result += 4;
                i++;
            }
            else if (s[i] == 'I')
            {
                result += 1;
            }
        }
        return result;
    }
};
