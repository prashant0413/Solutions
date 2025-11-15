class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        vector<int> cumCountOnes(n, 0);
        cumCountOnes[0] = (s[0] == '0') ? 0 : 1;
        for (int i = 1; i < n; i++) {
            cumCountOnes[i] = cumCountOnes[i - 1] + ((s[i] == '0') ? 0 : 1);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int countOne = cumCountOnes[j] - ((i - 1 >= 0) ? cumCountOnes[i - 1] : 0);
                int countZero = (j - i + 1) - countOne;

                if (countZero * countZero > countOne) {
                    int skip = countZero * countZero - countOne;
                    j += skip - 1;
                } 

                else if (countZero * countZero == countOne) {
                    res++;
                }

                else {
                    res++;
                    int k = sqrt(countOne) - countZero;
                    int nextJ = j + k;

                    if (nextJ >= n) {
                        res += (n - 1) - j;
                        break;
                    } else {
                       res += k; 
                    }
                    j = nextJ;
                }
            }
        }
        return res;
    }
};
