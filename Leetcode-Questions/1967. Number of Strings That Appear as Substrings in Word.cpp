// Apporoach 1
// TC = O(N*M*K)
// SC = O(1)
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (string &s: patterns) {
            if (word.find(s) != string::npos)
                cnt++;
        }
        return cnt;
    }
};
