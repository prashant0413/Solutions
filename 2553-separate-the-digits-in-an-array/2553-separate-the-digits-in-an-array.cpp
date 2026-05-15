class Solution {
    vector<int> ans;
public:
    void solve(int n) {
        vector<int> temp;
        while (n != 0) {
            temp.push_back(n % 10);
            n /= 10;
        }

        for (int i = temp.size() - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }

    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            solve(nums[i]);
        }
        return ans;
    }
};