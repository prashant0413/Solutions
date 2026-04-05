// Approach 1
// TC = O(log3(n))
// SC = O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 2) {
            if (n % 3) {
                return false;
            }
            n /= 3;
        }
        return n == 1;
    }
};

// Approach 2
// TC = O(1)
// SC = O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
