class MinStack {
public:
    int ind, st[30005], mn[30005];
    MinStack() {
        ind = -1;
    }
    
    void push(int val) {
        st[++ind] = val;
        mn[ind] = ind ? min(val, mn[ind-1]) : val;
    }
    
    void pop() {
        --ind;
    }
    
    int top() {
        return st[ind];
    }
    
    int getMin() {
        return mn[ind];
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
