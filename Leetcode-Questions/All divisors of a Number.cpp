class Solution {
  public:
    void print_divisors(int n) {
        vector<int> d;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cout << i << " ";
                if (n / i != i)
                    d.push_back(n / i);
            }
        }
        for (int i = d.size() - 1; i >= 0; i--)
            cout << d[i] << " ";
    }
};
