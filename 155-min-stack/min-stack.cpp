class MinStack {
public:
   
   stack<long long >st;
   long long  mini;
    MinStack() {
     mini=INT_MAX;
        
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty()) {
            mini= val;
            st.push(val);
        }
        else {
            if( val > mini) st.push(val);
            else {
                st.push(2*val - mini);
                mini=val;
            }
        }
    }
    
    void pop() {
        long long  n=st.top();
        st.pop();
        if(n < mini) {
            mini=2*mini - n;
        }
    }
    
    int top() {
        long long  n=st.top();
        if( n > mini) return (int) n;
        else {
            return (int)mini;
        }
        
    }
    
    int getMin() {
        return (int)mini;
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