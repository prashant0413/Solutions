// APPROACH 1: USING RECURSION
// TC: O(2^T . K)
// SC: O(K . N)
class Solution {
public:
    void solve(int i, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &res, int sum) {
        if (sum > target) return;

        if (sum == target) {
            res.push_back(temp);
            return;
        }

        if (i >= candidates.size()) return;

        if (candidates[i] + sum <= target) {
            temp.push_back(candidates[i]);
            solve(i, candidates, target, temp, res, sum + candidates[i]);
            temp.pop_back();
        }

        solve(i + 1, candidates, target, temp, res, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, candidates, target, temp, res, 0);
        return res; 
    }
};
