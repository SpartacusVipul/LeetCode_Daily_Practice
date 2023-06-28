class MinStack {
public:
    // nice trick
    // corresponding to every node, have another node which represents min till  then
    vector<int> inputVector;
    vector<int> minVector;
    MinStack() {
        
    }
    // while pushing into minstack, check if the top element of minstack is 
    // lower than new val
    // insert the minimum of both into the minstack
    void push(int val) {
        inputVector.push_back(val);
        if (minVector.size() > 0) {
            int minTillNow = min(val, minVector[minVector.size() - 1]);
            minVector.push_back(minTillNow);
        } else {
            minVector.push_back(val);
        }
    }
    
    void pop() {
        inputVector.pop_back();
        minVector.pop_back();
    }
    
    int top() {
        return inputVector[inputVector.size() - 1];
    }
    
    int getMin() {
        return minVector[minVector.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */