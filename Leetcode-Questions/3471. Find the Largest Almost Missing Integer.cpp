// Approach 1
// TC = O(n^2)
// SC = O(1)
class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        int[] count = new int[51];
        for (int i = 0; i <= n - k; i++) {
            boolean[] seen = new boolean[51];
            int j = i;
            while (j < i + k && j < n) {
                if (!seen[nums[j]]) {
                    count[nums[j]]++;
                    seen[nums[j]] = true;
                }
                j++;
            }
        }

        int ans = -1;
        for (int i = 0; i < 51; i++) {
            if (count[i] == 1) ans = i;
        }
        return ans;
    }
}
