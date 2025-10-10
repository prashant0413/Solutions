    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        // input section
        string s;
        int n, t;
        cin >> n;
        cin >> t;
        cin >> s;
     
        for (int i = 1; i <= t; i++)
        {
            for (int j = 0; j < s.length() - 1; j++)
            {
                if (s[j] == 'B' && s[j + 1] == 'G')
                {
                    swap(s[j], s[j + 1]);
                    j++;
                }
            }
        }
     
        // output section
        cout << s << endl;
        return 0;
    }
