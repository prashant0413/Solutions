class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int countOne = 0;
        int result = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                countOne++;
                i++;
            } else {
                result += countOne;
                while (i < n && s[i] == '0')
                    i++;
            }
        }
        return result;
    }
};
