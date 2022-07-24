class Solution
{
    string ans;
    public:
    
    void solve(string &s, int k, int i){
        if(i==s.length() || k==0){
            if(ans<s){
                ans = s;
            }
            return;
        }
        
        char mx = '0';
        for(int j=i+1; j<s.length(); j++){
            if(s[j]>s[i] && s[j]>mx){
                mx = s[j];
            }
        }
        
        solve(s, k, i+1);
        
        if(mx=='0'){
            return;
        }
        
        for(int j=i+1; j<s.length(); j++){
            if(s[j]==mx){
                swap(s[j], s[i]);
                solve(s, k-1, i+1);
                swap(s[j], s[i]);
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       ans = str;
       solve(str, k, 0);
       return ans;
    }
};