// APPROACH 1: BRUTE FORCE
// TC: O(N^2 . K)
// SC: O(N)
class Solution {
public:
    bool checkAnagram(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (n != m) return false;

        int freq[26] = {0};
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
            if (freq[i] != 0) return false;

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;

        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int k = 0; k < res.size(); k++) {
                if (checkAnagram(strs[i], res[k][0])) {
                    res[k].push_back(strs[i]);
                    found = true;
                    break;
                }
            }

            if (!found) {
                res.push_back({strs[i]});
            }
        }

        return res;
    }
};

// APPROACH 2: USING HASHMAP
// TC: O(N . K)
// SC: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mpp;

        for (int i = 0; i < n; i++) {
            string k = strs[i];
            sort(k.begin(), k.end());
            mpp[k].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto it: mpp) {
            res.push_back(it.second);
        }

        return res;
    }
};
