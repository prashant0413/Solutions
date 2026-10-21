// APPROACH 1: SORTING
// TC: O(N LOG N)
// SC: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// APPROACH 2: MIN-HEAP
// TC: O(N LOG K)
// SC: O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

// APPROACH 3: USING QUICK-SELECT ALGORITHM
// TC: O(N); WORST CASE O(N^2)
// SC: O(1)
class Solution {
public:
    int partition(vector<int> &nums, int L, int R) {
        int P = nums[L];
        int i = L + 1;
        int j = R;

        while (i <= j) {
            if (nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            if (nums[i] >= P) i++;
            if (nums[j] <= P) j--;
        }

        swap(nums[L], nums[j]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int L = 0;
        int R = n - 1;

        while (true) {
            int p = partition(nums, L, R);

            if (p == (k - 1)) return nums[p];
            else if (p > (k - 1)) R = p - 1;
            else L = p + 1;
        }

        return -1;
    }
};
