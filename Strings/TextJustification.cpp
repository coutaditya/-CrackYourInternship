// Just the brute force implementation (got accepted jaise-taise)

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        queue<string> q;
        vector<string> ans;
        
        int len=0;
        int l=0;
        int r=0;
        int n = words.size();
        
        while(r<n){
            if(len+words[r].length()>maxWidth){
                int den = (r-l-1);
                int num =  (maxWidth-len+1);
                
                string t = "";
                
                for(int i=l; i<r-2; i++){
                    t.append(words[i]+" ");
                    int gap = (num+den-1)/den;
                    num-=gap;
                    den--;
                    for(int j=0; j<gap; j++){
                        t.push_back(' ');
                    }
                }
                
                if(den==0){
                    t.append(words[r-1]);
                    while(t.length()!=maxWidth){
                        t.push_back(' ');
                    }
                    ans.push_back(t);
                }
                else{
                    t.append(words[r-2]+" ");
                    int gap = (num+den-1)/den;
                    for(int j=0; j<gap; j++){
                        t.push_back(' ');
                    }
                    t.append(words[r-1]);
                    ans.push_back(t);
                }
                
                l=r;
                len = 0;
            }
            else{
                len+=words[r].length()+1;
                r++;
            }
        }
        if(l<n){
            string t = "";
            for(int i=l; i<n; i++){
                t.append(words[i]);
                if(t.length()<maxWidth)
                    t.push_back(' ');
            }
            
            while(t.length()!=maxWidth){
                t.push_back(' ');
            }
            
            ans.push_back(t);
        }
        
        return ans;
    }
};