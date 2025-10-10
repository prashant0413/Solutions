    #include <bits/stdc++.h>
    using namespace std;
     
    int main() 
    {
        string s;
        cin >> s;
        int cnt = 0;
        vector<bool> check(26, false);
        for(int i = 0; i<s.length(); i++)
        {
            if(check[s[i] - 'a'] == true)
                continue;
            cnt++;
            check[s[i] - 'a'] = true;
        }
        if(cnt % 2 == 0)
          cout << "CHAT WITH HER!" << endl;
        else
          cout << "IGNORE HIM!" << endl;
        return 0;
    }
