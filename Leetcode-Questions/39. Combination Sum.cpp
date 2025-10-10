class Solution {
    vector<vector<int>> result;

    void solve(vector<int> &arr, int target, int i, vector<int> &temp) {
        if (target == 0) {
            result.push_back(temp);
            return;;
        }

        if (i == arr.size())
            return;

        if (arr[i] <= target) {
            temp.push_back(arr[i]);
            solve(arr, target - arr[i], i, temp);
            temp.pop_back();
        }
        solve(arr, target, i + 1, temp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return result;
    }
};
