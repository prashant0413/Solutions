// Approach 1
// TC = O(N)
// Sc = O(N)
class Solution {
public:
    string decodeString(string s) {
        stack<string> strSt;
        stack<int> numSt;
        int k = 0;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
                continue;
            }

            if (c == '[') {
                numSt.push(k);
                k = 0;
                strSt.push(string(1, c));
                continue;
            }

            if (c != ']') {
                strSt.push(string(1, c));
                continue;
            }

            string temp = "";
            while (strSt.top() != "[") {
                temp.insert(0, strSt.top());
                strSt.pop();
            }

            // remove the "["
            strSt.pop();

            // Get the new string
            string rep = "";
            int freq = numSt.top(); numSt.pop();
            for (int i = 0; i < freq; i++)
                rep += temp;
            
            // Add it to the stack
            strSt.push(rep);
        }

        string res = "";
        while (!strSt.empty()) {
            res.insert(0, strSt.top());
            strSt.pop();
        }
        return res;
    }
};
