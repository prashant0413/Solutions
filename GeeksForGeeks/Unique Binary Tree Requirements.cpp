// Approach 1
// TC = O(1)
// SC = O(1)
class Solution {
  public:
    bool isPossible(int a, int b) {
        if (a == b) return false;
        if (a == 1 && b == 3 || b == 1 && a == 3) return false;
        return true;
    }
};
