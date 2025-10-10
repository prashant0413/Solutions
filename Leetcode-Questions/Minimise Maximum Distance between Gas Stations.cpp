class Solution
{
    int numberStations(long double mid, vector<int> &stations)
    {
        int n = stations.size();
        int cntStations = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int numberBtn = ((stations[i + 1] - stations[i]) / mid);
            if ((stations[i + 1] - stations[i]) == (mid * numberBtn))
                numberBtn--;
            cntStations += numberBtn;
        }
        return cntStations;
    }

public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        long double low = 0;
        long double high = 0;

        for (int i = 0; i < n - 1; i++)
            high = max(high, (long double)stations[i + 1] - stations[i]);

        long double diff = 1e-6;
        while (high - low > diff)
        {
            long double mid = low + (high - low) / 2.0;
            int cnt = numberStations(mid, stations);
            if (cnt > k)
                low = mid;
            else
                high = mid;
        }
        return high;
    }
};
