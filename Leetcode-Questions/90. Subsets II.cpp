class Solution {
    vector<vector<int>> result;

    void solve(int i, vector<int> &nums, vector<int> &t) {    
        result.push_back(t);

        for (int ix = i; ix < nums.size(); ix++) {
            if (ix > i && nums[ix] == nums[ix - 1])
                continue;

            t.push_back(nums[ix]);
            solve(ix + 1, nums, t);
            t.pop_back();
        }        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> t;
        sort(nums.begin(), nums.end()); 
        solve(0, nums, t);
        return result;
    }
};
