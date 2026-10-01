// APPROACH 1: BRUTE FORCE
// TC: O(N!)
// SC: O(N)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.find(s1) != string::npos) return true;
        string per = s1;
        next_permutation(begin(per), end(per));
        while (s2.find(per) == string::npos) {
            if (per == s1) return false;
            next_permutation(begin(per), end(per));
        }

        return true;
    }
};

// APPROACH 2: BETTER 
// TC: O((N - M). M LOG M)
// SC: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int m = s1.length();

        sort(begin(s1), end(s1));

        for (int i = 0; i <= n - m; i++) {
            string str = s2.substr(i, m);
            sort(begin(str), end(str));
            if (str == s1) return true;
        }

        return false;
    }
};
