// APPROACH 1: NAIVE APPROACH RECURSION AND MEMOIZATION
// TC: O(ab(a + b + min(a, b)))
// SC: O(ab(a + b))
class Solution {
private:
    bool solve(int a, int b, vector<vector<int>> &t) {
        // CHOCLATE NHI HAI MATLAB PLAYER LOSES
        if (a == 0 && b == 0) return false;
        
        // AGAR EK DABBA KHALI TOH DUSRE SE PURA KHA KE PLAYER JEET JAYEGA
        if (a == 0 || b == 0) return true;
        
        // AGAR PEHLE HI CALCULATE KR LIYE TOH
        if (t[a][b] != -1) return t[a][b];
        
        // PHELE WALE DABBE SE CHOCOLATE KHA KE DEKH
        for (int i = 1; i <= a; i++) {
            if (!solve(a - i, b, t)) {
                return t[a][b] = true;
            }
        }
        
        // DUSRE WALE DABBE SE CHOCOLATE KHA KE DEKH
        for (int i = 1; i <= b; i++) {
            if (!solve(a, b - i, t)) {
                return t[a][b] = true;
            }
        }
        
        // DONO SE KHA KE DEKH
        for (int i = 1; i <= min(a, b); i++) {
            if (!solve(a - i, b - i, t)) {
                return t[a][b] = true;
            }
        }
        
        // PLAYER NHI JEET PA RHA
        return t[a][b] = false;
    }
public:
    bool game(int a, int b) {
        vector<vector<int>> t(a + 1, vector<int>(b + 1, -1));
        return solve(a, b, t);
    }
};
