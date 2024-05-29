class MyStack {
private:
    queue<int> q;
    int top_val;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        top_val=x;
    }
    
    int pop() {
        int val;
        for(int i=0;i<q.size()-1;i++){
            val = q.front();
            q.pop();
            q.push(val);
        }
        top_val=val;
        val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return top_val;
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */