// APPROACH 1: BRUTE FOCE USING IN-BUILT NEXT PERMUTAION
// TC: O(N . N!)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        int totalCombinations = 1;
        for (int i = 1; i <= n; i++) totalCombinations *= i;
        for (int i = 1; i <= totalCombinations; i++) {
            res.push_back(nums);
            next_permutation(begin(nums), end(nums));
        }

        return  res;
    }
};

// APPROACH 2: USING RECUSION
// TC: O(N . N!)
// SC: O(N)
class Solution {
    int n;
public:
    void solve(int i, vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &vis) {
        if (i >= n) {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            vis[j] = true;
            temp.push_back(nums[j]);
            solve(i + 1, nums, ans, temp, vis);
            temp.pop_back();
            vis[j] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> vis(n, false);
        solve(0, nums, ans, temp, vis);
        return ans;
    }
};
