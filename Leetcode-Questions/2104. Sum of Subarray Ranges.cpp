class Solution {
    vector<int> findN(vector<int> &arr) {
        int n = arr.size();
        vector<int> v(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> findP(vector<int> &arr) {
        int n = arr.size();
        vector<int> v(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
    long long largest(vector<int> &arr) {
        vector<int> nle = findN(arr);
        vector<int> ple = findP(arr);
        long long total = 0;
        for (int i = 0; i < arr.size(); i++) {
            int leftMax = i - ple[i];
            int rightMax = nle[i] - i;
            total += (leftMax * rightMax * 1LL * arr[i]);
        }
        return total;
    }
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
    long long smallest(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        long long total = 0;
        for (int i = 0; i < arr.size(); i++) {
            int leftMax = i - pse[i];
            int rightMax = nse[i] - i;
            total += (leftMax * rightMax * 1LL * arr[i]);
        }
        return total;
    }
public:
    long long subArrayRanges(vector<int>& arr) {
        return (largest(arr) - smallest(arr));
    }
};
