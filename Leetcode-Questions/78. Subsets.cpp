// APPROACH 1: USING BIT MANIPULATION
// TC: O(N . 2^N)
// SC: O(N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        int totalSubsets = 1 << n;
        vector<vector<int>> res;
    
        for (int i = 0; i < totalSubsets; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }

        return res;
    }
};


// APPROACH 2: USING RECURSION
// TC: O(2^N)
// SC: O(N)
class Solution {
public:
    void solve(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans) {
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, ans);
        temp.pop_back();
        solve(i + 1, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, temp, ans);
        return ans;
    }
};
