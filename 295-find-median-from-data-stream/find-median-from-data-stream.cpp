class MedianFinder {
public:
    // trick is tio use a min Heap and max heap.,
    // max heap is used to save all elements lower than current median 
    // min heap is used to save all elements greater than current median 
    // so idea is new element, if both min and max are zero (base case) then insert the element in mid
    // now if we get a new element, we check if num >= top from minHeap if yes, then swap num with top element 
    // and replace mid with top 
    // if num <= lower then swap num with top element and replace mid with top 
    // if mid is not INT_MIN, (INT_MIN is used to represnt invalid value is present in mid) 
    // then we  push lower of mid and num into maxHeap, higher of mid and num into minHeap
    //while getting if mid is not INMIN then return mid, else top of both heaps by 2 
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int mid = INT_MIN;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
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
            return mid;
        } else {
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