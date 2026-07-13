class MinStack {
public:
    stack<int> st;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minStack.empty() || value <= minStack.top()){
            minStack.push(value);
        }
        else{
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        if(st.empty()) return ;
        st.pop();
        minStack.pop();
    }
    
    int top() {
        if(st.empty()) return 0;
        return st.top();
    }
    
    int getMin() {
        if(minStack.empty()) return -1;
        else return minStack.top();
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