    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        // input section
        string s;
        cin >> s;
     
        // output section
        string str = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.')
                str += '0';
            else if (i < s.length() - 1)
            {
                if (s[i] == '-' and s[i + 1] == '.')
                {
                    str += '1';
                    i++;
                }
                else if (s[i] == '-' and s[i + 1] == '-')
                {
                    str += '2';
                    i++;
                }
            }
        }
     
        cout << str << endl;
        return 0;
    }
