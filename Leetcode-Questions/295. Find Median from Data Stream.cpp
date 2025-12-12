/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



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


// Approach 2
// TC = O(log(n))
// SC = O(n)
class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int size;
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if (left.empty() || num < left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        if (abs((int)left.size() - (int)right.size()) > 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
        size++;
    }
    
    double findMedian() {
        if (size & 1) {
            return (double)left.top();
        } else {
            return ((double)left.top() + (double)right.top()) / 2.0;
        }
    }
};
