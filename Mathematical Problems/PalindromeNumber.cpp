// Store number in a string and check

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string n = to_string(x);
        int i=0, j=n.length()-1;
        
        while(i<j){
            if(n[i]!=n[j]){
                return false;
            }
            i++; j--;
        }
        
        return true;
    }
};


// Store the last half reversed in a number and check with the first half

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};