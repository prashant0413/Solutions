    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        // input section
        string s;
        cin >> s;
     
        int cntLow = 0;
        int cntUp = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                cntUp++;
            if (s[i] >= 'a' && s[i] <= 'z')
                cntLow++;
        }
     
        if (cntLow >= cntUp)
        {
            for (int i = 0; i < s.length(); i++)
                s[i] = tolower(s[i]);
        }
        else
        {
            for (int i = 0; i < s.length(); i++)
                s[i] = toupper(s[i]);
        }
     
        // output section
        cout << s << endl;
        return 0;
    }
