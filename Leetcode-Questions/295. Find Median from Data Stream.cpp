// Approach 1
// TC = O(nlog(n))
// SC = O(n)
class MedianFinder {
    vector<double> data;
public:
    MedianFinder() {
        data.clear();
    }
    
    void addNum(int num) {
        data.push_back(num);
        sort(begin(data), end(data));
    }
    
    double findMedian() {
        if (data.size() & 1) {
            return data[data.size() / 2];
        } else {
            return (data[data.size() / 2] + data[data.size() / 2 - 1]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
