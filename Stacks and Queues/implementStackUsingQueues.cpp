// Just use a queue where you "push to front" by pushing to back and then rotating the queue until the new element is at the front 
// (i.e., size-1 times move the front element to the back).

class MyStack {
    queue<int> q;
public:
    MyStack() {
        while(!q.empty()) q.pop();
    }
    
    void push(int x) {
        q.push(x);
        for(int i=1; i<q.size(); i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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