class MinStack {
private:    
    int idx,current_min;
    int arr[3][10000];
public:
    MinStack() {
        idx = -1;
        current_min = INT_MAX;
    }
    
    void push(int val) {
        idx++;
        current_min = current_min < val ? current_min : val;
        arr[0][idx] = val;
        arr[1][idx] = current_min;
    }
    
    void pop() {
        current_min = idx > 0 ? arr[1][idx-1] : INT_MAX;
        idx--;
    }
    
    int top() {
        return arr[0][idx];
    }
    
    int getMin() {
        return arr[1][idx];
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
