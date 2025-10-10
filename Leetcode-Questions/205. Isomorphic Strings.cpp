class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> m1, m2;
        for (int i = 0; i < s.length(); i++)
        {
            char org = s[i];
            char rep = t[i];

            if (m1.find(org) != m1.end())
            {
                if (m1[org] != rep)
                    return false;
            }
            if (m2.find(rep) != m2.end())
            {
                if (m2[rep] != org)
                    return false;
            }
            m1[org] = rep;
            m2[rep] = org;
        }
        return true;
    }
};
