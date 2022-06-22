// Nearest Greater to Left Problem

class StockSpanner {
    stack<int> s;
    vector<int> v;
    vector<int> ans;
public:
    StockSpanner() {
        while(!s.empty()){
            s.pop();
        }
        v.resize(0);
    }
    
    int next(int price) {
        v.push_back(price);
        int n = v.size();
        
        while(!s.empty() && v[s.top()-1]<=price){
            s.pop();
        }
        
        if(s.empty()){
            s.push(n);
            return n;
        }
        else{
            int x = s.top();
            s.push(n);
            return (n-x);
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */