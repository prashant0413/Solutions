class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        vector<int> v;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0)
                st.push(arr[i]);
            else {
                if (st.empty() || st.top() < 0) {
                    st.push(arr[i]);
                } else {
                    while (!st.empty() && st.top() > 0) {
                        int x = st.top();
                        st.pop();
                        if (x == abs(arr[i]))
                            break;
                        else if (x > abs(arr[i])) {
                            st.push(x);
                            break;
                        }
                        if (st.empty() || st.top() < 0) {
                            st.push(arr[i]);
                            break;
                        }
                    }
                }
            }
        }
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
