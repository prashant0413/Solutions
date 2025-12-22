// Approach 1
// TC = O(n)
// SC = 1
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
      int n = nums.size();
      int xr = 0;
      for (int i = 0; i < n; i++) {
          xr ^= nums[i];
          xr ^= (i + 1);
      }
      int number = xr & ~(xr - 1);
      int zero = 0;
      int one = 0;
      for (int i = 0; i < n; i++) {
          if (number & nums[i]) {
              one ^= nums[i];
          } else {
              zero ^= nums[i];
          }
      }
  
      for (int i = 1; i <= n; i++) {
          if (number & i) {
              one ^= i;
          } else {
              zero ^= i;
          }
      }
  
      int cnt = 0;
      for (int i = 0; i < n; i++) {
          if (nums[i] == zero)
              cnt++;
      }
  
      if (cnt == 2)
          return {zero, one};
      return {one, zero};
    }
};

// Approach 2
// TC = O(n)
// Sc = O(1)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
        long long n = nums.size();
        // s - sn
        // s2 - sn2
        long long sn = (n * (n + 1)) / 2;
        long long sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
        long long s = 0, s2 = 0; 
        for (int i = 0; i < n; i++) {
            s += nums[i];
            s2 += (long long)nums[i] * (long long)nums[i];
        }
        long long val1 = s - sn;
        long long val2 = s2 - sn2;
        val2 = val2 / val1;
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        return {(int)x, (int)y};
    }
};
