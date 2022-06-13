// THIS IS A GOOGLE INTERVIEW QUEDSTION


// Mera Ghisa-Pita Solution (poor poor space complexity)
// We select tasks using the round robin method (one with higer priority is selected) in each cycle of n+1 tasks

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        int sz = tasks.size();
        for(int i = 0; i<sz; i++){
            m[tasks[i]]++;
        }
        
        priority_queue<pair<int, char> > pq;
        
        for(auto i:m){
            pq.push({i.second, i.first});
        }
        
        int time = 0;
        
        while(sz){
            int t = n+1;
            vector<pair<int, char> > v;
            
            while(t && pq.size()!=0){
                int x = pq.top().first;
                char c = pq.top().second;
                // cout<<c<<" ";
                pq.pop();
                
                x--;
                time++;
                t--;
                sz--;
                if(x!=0){
                    v.push_back({x, c});
                }
            }
            
            for(auto p:v){
                pq.push(p);
            }
            
            if(sz==0){
                break;
            }
            
            while(t!=0){
                // cout<<"1 ";
                time++;
                t--;
            }
            // cout<<"\n";
            
        }
        
        return time;
    }
};



// Better Solution (Not mine, mujhe toh samajh bhi ni aaya initially)
// Explanation: https://www.youtube.com/watch?v=eGf-26OTI-A&ab_channel=NickWhite

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        
        int char_freq[26] = {0};
        for(int i=0; i<sz; i++){
            char_freq[tasks[i]-'A']++;
        }
        
        sort(char_freq, char_freq+26);
        
        int max_val = char_freq[25];
        max_val--; // Because last cycle won't need free slots
        int free_slots = max_val*n;
        
        for(int i=24; i>=0; i--){
            free_slots -= min(char_freq[i], max_val);
        }
        
        // If still free slots remain, we will need extra time for them
        if(free_slots>0){
            return free_slots+sz;
        }
        // Else for each cycle of max_val, we will be able to find distinct tasks to fill free slots, and since max_val cycles are covered, no other frequency will create such problem. So we return tasks.length
        else{
            return sz;
        }
    }
};