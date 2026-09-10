// Approach 1 greedy
// TC = O(nlog(n))
// SC = O(n)
class Data {
  public:
    int st;
    int en;
    int i;
};

class Solution {
  public:
    struct cmp {
        bool operator()(Data &d1, Data &d2) {
            return d1.en < d2.en;
        }
    };
  
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        vector<Data> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].st = s[i];
            arr[i].en = f[i];
            arr[i].i = i;
        }
        
        sort(begin(arr), end(arr), cmp());
        
        vector<int> ans;
        int ft = arr[0].en;
        ans.push_back(arr[0].i + 1);
        for (int i = 1; i < n; i++) {
            if (arr[i].st > ft) {
                ft = arr[i].en;
                ans.push_back(arr[i].i + 1);
            }
        }
        
        sort(begin(ans), end(ans));
        return ans;
    }
};
