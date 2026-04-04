// Approach 1
// TC = O(2n)
// SC = O(26)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        vector<int> freq(26, 0);
        for (int i = 0; i < ransomNote.size(); i++) {
            freq[ransomNote[i] - 'a']++;
        }

        for (int i = 0; i < magazine.size(); i++) {
            freq[magazine[i] - 'a']--;
        }

        for (int i: freq) {
            if (i <= 0)
                continue;
            return false;
        }
        return true;
    }
};
