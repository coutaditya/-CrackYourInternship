// Use a priority queue to store elements according to their frequency and put them one by one from the queue

class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char, int> m;
        for(auto i:s){
            m[i]++;
        }
        
        priority_queue<pair<int, char> > q;
        for(auto i:m){
            q.push({i.second, i.first});
        }
        
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            ans.push_back(p.second);
            p.first--;
            if(!q.empty()){
                auto p1 = q.top();
                q.pop();
                ans.push_back(p1.second);
                p1.first--;
                if(p1.first>0) q.push(p1);
                if(p.first>0) q.push(p);
            }
            else{
                if(p.first!=0) return "";
            }
        }
        return ans;
    }
};