class MedianFinder {
public:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int mid = INT_MIN;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        cout << "add " << mid << " " << num << endl;
        if (mid == INT_MIN) {
            if (minHeap.size() == 0 && maxHeap.size() == 0) {
                mid = num;
                return;
            } 

            int right = minHeap.top();
            int left = maxHeap.top();

            if (num >= right) {
                minHeap.pop();
                minHeap.push(num);
                mid = right;
            } else if (num <= left) {
                maxHeap.pop();
                maxHeap.push(num);
                mid = left;
            } else {
                mid = num;
            }
        } else {
            int lower = min(mid, num);
            int higher = max(mid, num);
            minHeap.push(higher);
            maxHeap.push(lower);
            mid = INT_MIN;
        }
    }
    
    double findMedian() {
        
        if (mid != INT_MIN) {
            cout << mid << endl;
            return mid;
        } else {
            cout << (double)minHeap.top() + (double)maxHeap.top() << endl;;
            return ((double)minHeap.top() + (double)maxHeap.top()) / 2.0;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */