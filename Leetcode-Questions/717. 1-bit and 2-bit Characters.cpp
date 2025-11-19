class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if (n == 1 || bits[n - 2] == 0)
            return true;

        int i = n - 2;
        int cntOne = 0;
        while (i >= 0 && bits[i] != 0) {
            cntOne++;
            i--;
        }
        return (cntOne % 2 == 0) ? true : false;
    }
};
