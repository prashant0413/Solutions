    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        // input section
        int n;
        cin >> n;
     
        // output section
        if (n & 1)
            cout << -1 << endl;
        else
        {
            for (int i = n; i >= 1; i--)
                cout << i << " ";
            cout << endl;
        }
        return 0;
    }
