// Approach 1
// TC = O(log4(n))
// SC = O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        while (n > 3) {
            if (n % 4)
                return false;
            n /= 4;
        }
        return n == 1;
    }
};

// Approach 1
// TC = O(1)
// SC = o(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (0xaaaaaaaa & n) == 0;
    }
};
