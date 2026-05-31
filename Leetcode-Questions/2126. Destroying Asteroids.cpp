// Approach 1
// TC = O(nlog(n))
// SC = O(1)
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long m = mass;
        sort(begin(asteroids), end(asteroids));
        for (int i = 0; i < n; i++) {
            if (m < asteroids[i])
                return false;
            m += asteroids[i];
        }  
        return true;
    }
};
