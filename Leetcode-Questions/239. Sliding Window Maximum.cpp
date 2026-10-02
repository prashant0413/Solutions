// APPROACH 1: USING SLIDING WINDOW
// TC: O(N . K)
// SC: O(1)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 1) return nums;

        vector<int> ans;

        int i, j;
        i = j = 0;
        int maxi = nums[0];

        while (j < n) {
            maxi = max(maxi, nums[j]);
            if (j - i + 1 > k) {
                if (nums[i] == maxi) {
                    maxi = nums[j];
                    for (int c = i + 1; c < j; c++)
                        maxi = max(maxi, nums[c]);
                }
                i++;
            }

            if (j - i + 1 == k) {
                ans.push_back(maxi);
            }
            j++;
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
