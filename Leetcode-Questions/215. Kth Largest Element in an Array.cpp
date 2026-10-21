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


class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int P = nums[l];
        int i = l + 1;
        int j = r;

        while (i <= j) {
            if (nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            if (nums[i] >= P)
                i++;
            if (nums[j] <= P)
                j--; 
        }
        swap(nums[l], nums[j]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        int pivot = 0;

        while (true) {
            pivot = partition(nums, l, r);

            if (pivot == (k - 1))
                break;
            if (pivot > (k - 1))
                r = pivot - 1;
            else
                l = pivot + 1;
        }

        return nums[pivot];
    }
};
// using quickselect algorithm
// O(n) on average, O(n2) in the worst case
