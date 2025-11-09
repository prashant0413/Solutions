#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> arr1;
    arr1.assign(arr.begin(), arr.end());
    sort(arr1.begin(), arr1.end());

    vector<long long> sum1(n);
    vector<long long> sum2(n);
    long long s = 0;
    long long s1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        s += arr[i];
        s1 += arr1[i];
        sum1[i] = s;
        sum2[i] = s1;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            long long ans = sum1[r - 1];
            if (l - 2 >= 0)
                ans -= sum1[l - 2];
            cout << ans << endl;
        }
        else
        {
            long long ans = sum2[r - 1];
            if (l - 2 >= 0)
                ans -= sum2[l - 2];
            cout << ans << endl;
        }
    }

    return 0;
}
