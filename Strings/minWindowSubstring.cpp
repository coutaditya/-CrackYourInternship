// See minimum window substring problem from sliding window notes (variable sized window)

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char, int> m;
        unordered_set<char> S;
        
        for(auto st:p){
            S.insert(st);
            m[st]++;
        }
        
        int idx = -1;
        int size = INT_MAX;
        
        int i=0, j=0;
        int count = S.size();
        while(j<s.length()){
            if(count>0){
                if(S.count(s[j])!=0){
                    m[s[j]]--;
                    if(m[s[j]]==0){
                        count--;
                    }
                }
                j++;
            }
            else if(count==0){
                if(size>(j-i)){
                    size = j-i;
                    idx = i;
                }
                if(S.count(s[i])!=0){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
            else{
                if(S.count(s[i])!=0){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
        }
        
        while(i<s.length() && count==0){
            if(size>(j-i)){
                size = j-i;
                idx = i;
            }
            if(S.count(s[i])!=0){
                m[s[i]]++;
                if(m[s[i]]==1){
                    count++;
                }
            }
            i++;
        }
        
        if(idx == -1){
            return "-1";
        }
        
        return s.substr(idx, size);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
    return 0;
}  // } Driver Code Ends