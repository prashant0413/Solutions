#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int freq[26] = {0};
    for (auto &c : s)
    {
        freq[c - 'a']++;
    }

    int odd = 0;
    int even = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == 0)
            continue;
        if (freq[i] % 2)
            odd++;
        else
            even++;
    }
    int k = 0;
    while (even > 0 || odd > 0)
    {
        if (odd <= 1)
            break;

        even++;
        odd--;

        k = 1 - k;
    }
    if (!k)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
