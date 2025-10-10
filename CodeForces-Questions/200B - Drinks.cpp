    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        // input section
        int n;
        cin >> n;
        int *arr = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
     
        // output section
        cout << (float)sum / (float)n << endl;
        delete[] arr;
        return 0;
    }
