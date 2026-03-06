// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
    public boolean checkOnesSegment(String s) {
        int n = s.length();
        int cnt = 0;
        int i = 0;
        while (i < n) {
            if (s.charAt(i) == '1') {
                cnt++;
                while (i < n && s.charAt(i) == '1')
                    i++;
            } else {
                i++;
            }
        }
        return cnt == 1;
    }
}

// Approach 2
// TC = O(N)
// SC = O(1)
class Solution {
    public boolean checkOnesSegment(String s) {
        return s.indexOf("01") == -1 ? true : false;
    }
}
