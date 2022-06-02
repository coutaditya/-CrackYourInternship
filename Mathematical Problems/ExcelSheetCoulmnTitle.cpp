// Simple Recursive Code (not much to explain)

class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber == 0){
            return "";
        }
        
        int d = columnNumber%26-1;
        if(d==-1) d = 25;
        
        string ans = convertToTitle((columnNumber-1)/26);
        ans.push_back((char)(d+'A'));
        
        return ans;
    }
};