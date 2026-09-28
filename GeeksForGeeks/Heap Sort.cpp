// APPROACH 1: HEAP SORT
// TC: O(N LOG N)
// SC: O(1)
class Solution {
  private:
    void heapifyDown(vector<int> &arr, int i, int n) {
        while (true) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            int maxi = i;
            
            if (left < n && arr[maxi] < arr[left]) maxi = left;
            if (right < n && arr[maxi] < arr[right]) maxi = right;
            
            if (maxi == i) break;
            swap(arr[i], arr[maxi]);
            i = maxi;
        }
    }
  
    void heapify(vector<int> &arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyDown(arr, i, n);
    } 
  public:
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        heapify(arr, n);
        for (int i = 1; i <= n - 1; i++) {
            swap(arr[0], arr[n - i]);
            heapifyDown(arr, 0, n - i);
        }
    }
};
