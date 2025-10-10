class Solution {
    vector<vector<int>> result;

    void solve(int ix, int target, vector<int> &arr, vector<int> &t) {
        if (target == 0) {
            result.push_back(t);
            return;
        }

        for (int i = ix; i < arr.size(); i++) {
            if (i > ix && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            t.push_back(arr[i]);
            solve(i + 1, target - arr[i], arr, t);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        solve(0, target, candidates, t);
        return result;
    }
};
