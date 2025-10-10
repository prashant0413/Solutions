/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below od sorts the stack s
you are required to complete the below method */
void insert(int x, stack<int> &s) {
    if (s.empty() || s.top() <= x) {
        .push(x);
        return;
    }
    int a = s.top();
    s.pop();
    insert(x,s);
    s.push(a);
}
void sorting(stack<int> & s) {
    if (s.size() > 0) {
        int x = s.top();
        s.pop();
        sorting(s);
        insert(x,s);
    }
}

void SortedStack ::sort() {
    // Your code here
    sorting(s);
}
