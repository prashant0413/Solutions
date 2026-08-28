// Approach 1
// TC = O(n)
// SC = O(n)
class Solution {
public:
    char midChar = '$';
    int halfLen = 0;
    string result = "";

    bool solve(int i, string& s, string& target, int count[], bool greater, string& curr) {
        if (curr.length() == halfLen) {
            string candidate = curr;
            string rightHalf = curr;
            reverse(begin(rightHalf), end(rightHalf));
            if (midChar != '$') {
                candidate += midChar;
            }
            candidate += rightHalf;

            if (candidate > target) {
                result = candidate;
                return true;
            }

            return false;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c - 'a'] == 0) continue;
            if (!greater && c < target[i]) continue;
            curr.push_back(c);
            count[c - 'a']--;
            bool isGreater = greater || c > target[i];

            if (solve(i + 1, s, target, count, isGreater, curr)) return true;

            count[c - 'a']++;
            curr.pop_back();
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        int count[26] = {0};
        for (char ch: s) {
            count[ch - 'a']++;
        }

        int oddCount = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] & 1) {
                oddCount++;
                midChar = (char)(i + 'a');
            }
        }

        if (oddCount > 1) return "";
        
        for (int c = 0; c < 26; c++) {
            count[c] = count[c] / 2;
        }
        halfLen = n / 2;

        string curr = "";
        solve(0, s, target, count, false, curr);
        return result;
    }
};
