#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int h, m;
        cin >> h >> m;
        arr.push_back({h, m});
    }

    int mini = 1;
    int simon = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first == arr[i - 1].first && arr[i].second == arr[i - 1].second)
            simon++;
        else
        {
            if (simon > mini)
            {
                mini = simon;
            }
            simon = 1;
        }
    }

    if (simon > mini)
    {
        mini = simon;
    }

    cout << mini << endl;
    return 0;
}
