// We had to implement queue using 2 stacks such that amortized cost is O(1)
//  implement the queue such that each operation is amortized O(1) time complexity.
// In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

// In the below implementation, s1 is the input stack s2 is the output stack


class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans = peek();
        s2.pop();
        
        return ans;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return s2.top();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */