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
