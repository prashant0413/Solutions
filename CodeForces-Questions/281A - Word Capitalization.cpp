    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        // input section
        string s;
        cin >> s;
     
        if (s[0] >= 'A' && s[0] <= 'Z')
        {
            cout << s << endl;
            return 0;
        }
        s[0] = toupper(s[0]);
        cout << s << endl;
        return 0;
    }
