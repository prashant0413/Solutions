// Problem 258A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;

    string s;
    int i = 0;
    while (i < a.length())
    {
        if (a[i] == '0')
        {
            s += a.substr(i + 1);
            break;
        }
        s += a[i];
        i++;
    }

    if (i == a.length()) {
        cout << s.substr(1) << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}
