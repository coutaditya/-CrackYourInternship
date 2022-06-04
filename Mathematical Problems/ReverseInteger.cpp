// My Solution: Using STL and string

class Solution {
public:
    void reverse(string &s){
        int n = s.length();
        int i=0, j=n-1;
        
        while(i<j){
            swap(s[i], s[j]);
            i++; j--;
        }
    }
    
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        
        if(x<0){
            return -1*reverse(-1*x);
        }
        
        string s = to_string(x);
        reverse(s);
        long n = stol(s);
        
        if(n>INT_MAX){
            return 0;
        }
        
        else return n;
    }
};


// Better Solution 
// Here line 44 checks overflow 

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x) {
            long temp = ans * 10 + x % 10;
            if (temp>INT_MAX || temp<INT_MIN)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
};