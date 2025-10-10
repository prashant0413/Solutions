    #include <bits/stdc++.h>
    using namespace std;
     
    int main() 
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i = 0; i<n; i++)
          cin >> arr[i];
          
        int min = INT_MAX;
        int max = INT_MIN;
        int minIdx = -1;
        int maxIdx = -1;
        
        for(int i =0 ; i<n; i++)
        {
          if(arr[i] <= min)
          {
            minIdx = i;
            min = arr[i];
          }
        }
     
        int count = 0;    
        for(int i = 0; i<n; i++)
        {
          if(minIdx < n -1)
          {
            swap(arr[minIdx], arr[minIdx + 1]);
            count++;
            minIdx++;
          }
        }
        
        for(int i =0 ; i<n; i++)
        {
          if(arr[i] > max)
          {
            maxIdx = i;
            max = arr[i];
          }
        }
     
        for(int i = 0; i<n; i++)
        {
          if(maxIdx > 0)
          {
            swap(arr[maxIdx], arr[maxIdx - 1]);
            count++;
            maxIdx--;
          }
        }
        
        cout << count << endl;    
        
        delete[] arr;
        return 0;
    }
