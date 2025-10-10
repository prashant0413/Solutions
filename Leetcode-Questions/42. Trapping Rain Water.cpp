class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suf(n, 0);
        suf[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], height[i]);
        }
        int total = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, height[i]);
            int leftMax = maxi;
            int rightMax = suf[i];
            if (height[i] < leftMax && height[i] < rightMax)
                total += min(leftMax, rightMax) - height[i];
        }
        return total;
    }
};

/*
Time complexity = O(2n)
Space complexity = O(n) : only for suffix array
*/


class Solution {
public:
    int trap(vector<int>& arr) {
        int lMax = 0;
        int rMax = 0;
        int total = 0;
        int l = 0;
        int r = arr.size() - 1;
        while (l < r) {
            if (arr[l] < arr[r]) {
                if (lMax > arr[l]) {
                    total += lMax - arr[l];
                } else {
                    lMax = arr[l];
                }
                l++;
            } else {
                if (rMax > arr[r]) {
                    total += rMax - arr[r];
                } else {
                    rMax = arr[r];
                }
                r--;
            }
        }
        return total;
    }
};

/*
Time complexity = O(n)
Space complexity = O(1)
*/
