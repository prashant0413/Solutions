// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> st;
        for (char &c: s) {
            if (st.count(c))
                return c;
            st.insert(c);
        }
        return '0';
    }
};

// Approach 2
// TC = O(N)
// SC = O(26) => O(1)
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> freq(26, 0);
        for (char &c: s) {
            freq[c - 'a']++;
            if (freq[c - 'a'] > 1)
                return c;
        }
        return '0';
    }
};
