    #include <bits/stdc++.h>
    using namespace std;
     
    bool checkDigit(int year)
    {
        int arr[4] = {-1};
        int i = 0;
        while (year != 0)
        {
            int rem = year % 10;
            arr[i] = rem;
            i++;
            year = year / 10;
        }
     
        if (arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[3] || arr[0] == arr[2] || arr[0] == arr[3] || arr[1] == arr[3])
            return false;
        return true;
    }
     
    int main()
    {
        // input section
        int year;
        cin >> year;
     
        // solution
        int ans = year;
        bool cnt = true;
        while (cnt)
        {
            ans++;
            if (checkDigit(ans) == true)
                cnt = false;
        }
        cout << ans << endl;
        return 0;
    }
