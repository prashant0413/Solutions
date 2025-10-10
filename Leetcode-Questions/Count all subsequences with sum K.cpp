class Solution{
    int solve(vector<int> &nums, int i, int s, int k) {
        if (i >= nums.size()) {
            if (s == k) {
                return 1;
            }
            return 0;
        }
        s += nums[i];
        int l = solve(nums, i + 1, s, k);
        s -= nums[i];
        int r = solve(nums, i + 1, s, k);
        return l + r;
    }
    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        int cnt = solve(nums, 0, 0, k);
        return cnt;
    }
};
