class Solution
{
    bool isDigit(char c)
    {
        return c >= '0' and c <= '9';
    }

public:
    int myAtoi(string s)
    {
        long long result = 0;
        int n = s.length();
        int i = 0;
        bool sign = false; // false for '+' true for '-'

        // 1. Leading white spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. signedness
        if (s[i] == '+' || s[i] == '-')
        {
            if (s[i] == '+')
                i++;
            else if (s[i] == '-')
            {
                i++;
                sign = true;
            }
        }

        // 3. conversion
        while (i < n && isDigit(s[i]))
        {
            int digit = s[i] - '0';
            result = result * 10 + digit;
            if (result > INT_MAX)
            {
                if (sign)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            i++;
        }
        if (sign)
            result *= -1;
        return (int)result;
    }
};
