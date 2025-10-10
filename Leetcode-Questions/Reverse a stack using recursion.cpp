
class Solution {
    void insertBottom(int x, stack<int> &St) {
        if (St.empty()) {
            St.push(x);
            return;
        }
        int a = St.top();
        St.pop();
        insertBottom(x, St);
        St.push(a);
    }
  public:
    void reverse(stack<int> &St) {
        // code here
        if (St.size() > 0) {
            int x = St.top();
            St.pop();
            reverse(St);
            insertBottom(x, St);
        }
    }
};
