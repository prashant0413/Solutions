    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        // input section
        int n;
        cin >> n;
        string s;
        cin >> s;
     
        int count = 0;
        char last = s[0];
        for (int i = 1; i < s.length(); i++)
        {
            if (last == s[i])
                count++;
            else
            {
                last = s[i];
            }
        }
     
        // output section
        cout << count << endl;
        return 0;
    }
