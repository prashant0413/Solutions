// TC = O(2n)
// SC = O(n)
class Solution {
  public:
    bool isOperator(char c) {
    	if (c >= 'a' and c <= 'z' || c >= '0' and c <= '9' || c >= 'A' and c <= 'Z')
    		return true;
    	return false;
    }
    
    int priority(char c) {
    	if (c == '^')
    		return 3;
    	if (c == '*' || c == '/')
    		return 2;
    	if (c == '+' || c == '-')
    		return 1;
    	return -1;
    }
    
    string infixToPostfix(string &s){
    	int n = s.length();
    	stack<char> st;
    	string ans = "";
    	for (int i = 0; i < n; i++) {
    		if (isOperator(s[i])) {
    			ans += s[i];
    		} else if (s[i] == '(') {
    			st.push('(');
    		} else if (s[i] == ')') {
    			while (!st.empty() && st.top() != '(') {
    				ans += st.top(); st.pop();
    			}
    			st.pop();
    		} else {
    			while (!st.empty() && s[i] != '^' && priority(s[i]) <= priority(st.top())) {
    				ans += st.top(); st.pop();
    			}
    			st.push(s[i]);
    		}
    	}
    	while (!st.empty()) {
    		ans += st.top(); st.pop();
    	}
    	return ans;
    }
};
