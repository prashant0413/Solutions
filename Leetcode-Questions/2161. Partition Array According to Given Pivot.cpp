// Approach 1
// TC = O(3N)
// SC = O(1)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        
        // first taking smaller than pivot
        for (int i: nums) {
            if (i < pivot)
                ans.push_back(i);
        }

        // second taking equal to pivot
        for (int i: nums) {
            if (i == pivot)
                ans.push_back(i);
        }

        // now larger than pivot
        for (int i: nums) {
            if (i > pivot)
                ans.push_back(i);
        }

        return ans;
    }
};

// Approach 2
// TC = O(2N)
// SC = O(1)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int l = 0;
        int h = n - 1;
        int i = 0;
        int j = n - 1;
        while (i < n && j >= 0) {
            if (nums[i] < pivot)
                ans[l++] = nums[i];
            if (nums[j] > pivot)
                ans[h--] = nums[j];
            i++;
            j--;
        }

        while (l <= h) {
            ans[l] = pivot;
            l++;
        }

        return ans;
    }
};
