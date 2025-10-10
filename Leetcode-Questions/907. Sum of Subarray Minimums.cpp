class Solution {
    vector<int> findNse(vector<int> &arr) {
        int n = arr.size();
        vector<int> v(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> findPse(vector<int> &arr) {
        int n = arr.size();
        vector<int> v(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        long long total = 0;
        int mod = int(1e9 + 7);
        for (int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }
        return (int)total;
    }
};
