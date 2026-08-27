// Approach 1
// TC = O(n)
// SC = O(n)
class Solution {
public:
    bool solve(int i, string &s, string &target, string &curr, string &result, bool greater, int count[]) {
        if (i == target.length()) {
            if (greater) {
                result = curr;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0) continue;
            if (!greater && ch < target[i]) continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(i + 1, s, target, curr, result, isGreater, count)) {
                return true;
            } 

            curr.pop_back();
            count[ch - 'a']++;
        }
        
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        int count[26] = {0};
        for (char c: s) {
            count[c - 'a']++;
        }

        string result = "";
        string curr = "";
        return solve(0, s, target, curr, result, false, count) ? result : "";
    }
};
