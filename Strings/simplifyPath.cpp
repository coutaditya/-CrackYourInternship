// My Ghisa-Pita Solution :p
// Better Solution: https://leetcode.com/problems/simplify-path/discuss/1050620/C%2B%2B-or-Stack-or-O(n)-0ms-Beats-100-or-Easy-Explanation

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int n = path.length();
        
        string npath = "";
        for(int i=0; i<n; i++){
            if(i!=0 && path[i-1]=='/' && path[i]=='/'){
                continue;
            }
            else{
                npath.push_back(path[i]);
            }
        }
        
        n = npath.length();
        
        cout<<npath<<"\n";
        
        int i=0;
        while(i<n){
            if(npath[i]=='/'){
                if(npath.substr(i, 3)=="/.." && ((i+3<n && npath[i+3]=='/') || (i+3==n) ) ){
                    if(ans.length()>=2){
                        while(ans[ans.length()-1]!='/'){
                            ans.pop_back();
                        }
                        ans.pop_back();
                    }
                    
                    i+=3;
                    
                }
                else if(npath.substr(i, 2)=="/." && ((i+2<n && npath[i+2]=='/') || (i+2==n))){
                    i+=2;
                }
                else{
                    ans.push_back(npath[i]);
                    i++;
                }
            }
            else{
                ans.push_back(npath[i]);
                i++;
            }
        }
        
        if(ans.size()!=1){
            while(ans.size()!=0 && ans[ans.size()-1]=='/'){
                ans.pop_back();
            }
        }
        
        if(ans.size()==0){
            return "/";
        }
        
        return ans;
    }
};