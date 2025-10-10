    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        // input section
        string s;
        getline(cin, s);
     
        int one = 0;
        int two = 0;
        int three = 0;
        for (int i = 0; i < s.length(); i += 2)
        {
            if (s[i] - '0' == 1)
                one++;
            else if (s[i] - '0' == 2)
                two++;
            else
                three++;
        }
     
        for (int i = 0; i < s.length(); i += 2)
        {
            if (one != 0)
            {
                s[i] = '1';
                one--;
            }
            else if (two != 0)
            {
                s[i] = '2';
                two--;
            }
            else
            {
                s[i] = '3';
                three--;
            }
        }
     
        // output
        cout << s << endl;
        return 0;
    }
