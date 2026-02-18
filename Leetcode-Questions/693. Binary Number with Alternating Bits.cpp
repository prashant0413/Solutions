// Approach 1
// TC = O(log(n))
// SC = O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> b(n);
        int bits = log2(n);
        for (int i = 0; i <= bits; i++) {
            if (b[i] == b[i + 1])
                return false;
        }
        return true;
    }
};


// Approach 2
// TC = O(log(n))
// SC = O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int currBit = n % 2;
        n /= 2;
        while (n > 0) {
            if (currBit == n % 2)
                return false;
            currBit = n % 2;
            n /= 2;
        }
        return true;
    }
};

// Approach 3
// TC = O(k) where k is number of set bits
// SC = O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int counter = n & 1;
        n >>= 1;
        for (int i = 1; i < 32; i++) {
            if (n == 0)
                break;
            if ((n & 1) == counter)
                return false;
            counter = 1 - counter;
            n >>= 1;
        }
        return true;
    }
};

// Apporach 4
// TC = O(1)
// SC = O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int result = n ^ (n >> 1);
        return (result & (result + 1)) == 0;
    }
};
