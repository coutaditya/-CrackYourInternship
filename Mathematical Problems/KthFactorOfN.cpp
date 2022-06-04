// TC: O(sqrt(n)) SC: O(1)
// First we run a loop from 1 to <sqrt(n), if we get a factor and count = k, we return it if not
// We move from sqrt(n) to 1 and if we get a factor and count = k, we return (n/i)
// If still we dont get the required factor then it doesnt exist so we return -1

class Solution {
public:
    int kthFactor(int n, int k) {
        
        int c = 0;
        int i;
        for(i=1; i*i<n; i++){
            if(n%i==0){
                c++;
                if(c==k) return i;
            }
        }
        for(int i=sqrt(n); i>=1; i--){
            if(n%i==0){
                c++;
                if(c==k) return (n/i);
            }
        }
        
        return -1;
    }
};