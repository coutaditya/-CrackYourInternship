class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        cout<<a<<" "<<b<<"\n";
        
        int carry = 0, i;
        string ans;
        
        for(i=0; i<min(n, m); i++){
            int d = ((a[i]-'0')+(b[i]-'0')+carry);
            if(d%2==0){   
                ans.push_back('0');
            }
            else{
                ans.push_back('1');
            }
            carry = ((a[i]-'0')+(b[i]-'0')+carry)/2;
        }
        while(i<n){
            int d = ((a[i]-'0')+carry);
            if(d%2==0){   
                ans.push_back('0');
            }
            else{
                ans.push_back('1');
            }
            carry = (((a[i]-'0')+carry)/2);
            i++;
        }
        while(i<m){
            int d = ((b[i]-'0')+carry);
            if(d%2==0){   
                ans.push_back('0');
            }
            else{
                ans.push_back('1');
            }
            carry = (((b[i]-'0')+carry)/2);
            i++;
        }
        
        if(carry){
            ans.push_back('1');
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};