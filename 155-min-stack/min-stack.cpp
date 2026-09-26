class MinStack {
    stack<int> s,st;
public:
    MinStack() {
    }
    
    void push(int value) {
        s.push(value);
        if(st.empty() || value<=st.top())st.push(value);
    }
    
    void pop() {
        if(s.top()==st.top())st.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */