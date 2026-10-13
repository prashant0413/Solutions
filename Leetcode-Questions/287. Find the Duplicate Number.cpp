// APPROACH 1: USING SET
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int &i: nums) {
            if (st.count(i)) return i;
            st.insert(i);
        }
        return -1;
    }
};

// APPROACH 2: USING HARE AND TORTOISE TECHNIQUE
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int slow = nums[0];
        int fast = nums[0];

        // Move one time both
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
